/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:55:05 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/19 17:55:21 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_map_visited(t_game *game)
{
	int	i;

	game->visited = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->visited)
		exit_game(game, "Error\nMalloc failed");
	game->visited[game->map_height] = NULL;
	i = 0;
	while (game->map[i])
	{
		game->visited[i] = ft_strdup(game->map[i]);
		i++;
	}
}

static void	init_map_visited(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->visited[i])
	{
		j = 0;
		while (game->visited[i][j])
		{
			game->visited[i][j] = '0';
			j++;
		}
		i++;
	}
}

static int	find_collectible(t_game *game, int x, int y, int collectible)
{
	if (game->map[x][y] != '1' && game->visited[x][y] != '1'
		&& game->map[x][y] != 'E' && collectible != game->collectible)
	{
		game->visited[x][y] = '1';
		if (game->map[x][y] == 'C' && game->visited[x][y] != '2')
		{
			game->visited[x][y] = '2';
			collectible++;
			if (collectible == game->collectible)
				return (1);
		}
		if (find_collectible(game, x - 1, y, collectible))
			return (1);
		if (find_collectible(game, x + 1, y, collectible))
			return (1);
		if (find_collectible(game, x, y - 1, collectible))
			return (1);
		if (find_collectible(game, x, y + 1, collectible))
			return (1);
	}
	return (0);
}

static int	find_exit(t_game *game, int x, int y)
{
	if (game->map[x][y] != '1' && game->visited[x][y] != '1')
	{
		game->visited[x][y] = '1';
		if (game->map[x][y] == 'E')
			return (1);
		if (find_exit(game, x - 1, y))
			return (1);
		if (find_exit(game, x + 1, y))
			return (1);
		if (find_exit(game, x, y - 1))
			return (1);
		if (find_exit(game, x, y + 1))
			return (1);
	}
	return (0);
}

void	check_path(t_game *game)
{
	int	i;
	int	j;

	create_map_visited(game);
	init_map_visited(game);
	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				if (!find_collectible(game, i, j, 0))
					exit_game(game, "Error\nNo valid path");
				init_map_visited(game);
				if (!find_exit(game, i, j))
					exit_game(game, "Error\nNo valid path");
			}
		}
	}
}
