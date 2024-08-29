/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:40 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/19 16:48:24 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg_ext(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (len > 4)
	{
		if (argv[1][len - 1] == 'r' && argv[1][len - 2] == 'e'
			&& argv[1][len - 3] == 'b' && argv[1][len - 4] == '.')
			return (1);
	}
	return (0);
}

void	exit_game(t_game *game, char *error)
{
	if (game->map)
		ft_free_strs(game->map);
	if (game->visited)
		ft_free_strs(game->visited);
	if (game->sprite_floor)
		mlx_destroy_image(game->mlx, game->sprite_floor);
	if (game->sprite_end)
		mlx_destroy_image(game->mlx, game->sprite_end);
	if (game->sprite_wall)
		mlx_destroy_image(game->mlx, game->sprite_wall);
	if (game->sprite_collectible)
		mlx_destroy_image(game->mlx, game->sprite_collectible);
	if (game->sprite_player)
		mlx_destroy_image(game->mlx, game->sprite_player);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	ft_error(error);
	exit(0);
}

int	close_with_cross(t_game *game)
{
	exit_game(game, "");
	return (0);
}
