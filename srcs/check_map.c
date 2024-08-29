/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:25:00 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/17 18:25:55 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (i != 0 && game->map_width != len)
			exit_game(game, "Error\nInvalid map size");
		game->map_width = len;
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == game->map_height)
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					exit_game(game, "Error\nInvalid wall");
				j++;
			}
		}
		else
		{
			if (game->map[i][0] != '1')
				exit_game(game, "Error\nInvalid wall");
			if (game->map[i][game->map_width - 1] != '1')
				exit_game(game, "Error\nInvalid wall");
		}
		i++;
	}
}

void	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos_x = i;
				game->player_pos_y = j;
				game->player++;
			}
			else if (game->map[i][j] == 'C')
				game->collectible++;
			else if (game->map[i][j] == 'E')
				game->end++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				exit_game(game, "Error\nInvalid elements");
		}
	}
	if (game->player != 1 || game->collectible < 1 || game->end != 1)
		exit_game(game, "Error\nInvalid elements");
}
