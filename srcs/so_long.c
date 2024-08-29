/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:41:20 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/19 16:46:52 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialisation(t_game *game, char **argv)
{
	game->map = NULL;
	game->visited = NULL;
	game->filename = argv[1];
	game->player = 0;
	game->collectible = 0;
	game->end = 0;
	game->nb_move = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->img_size = 50;
	game->map_width = 0;
	game->map_height = 0;
	game->window_width = 0;
	game->window_height = 0;
	game->sprite_player = NULL;
	game->sprite_collectible = NULL;
	game->sprite_end = NULL;
	game->sprite_floor = NULL;
	game->sprite_wall = NULL;
	game->window = NULL;
	game->mlx = 0;
}

static void	check_error(t_game *game)
{
	check_rectangle(game);
	check_elements(game);
	check_walls(game);
	check_path(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Error\nWrong number of arguments");
	if (!check_arg_ext(argv))
		ft_error("Error\nBad extension");
	game = malloc(sizeof(t_game) * (1));
	if (!game)
		ft_error("Error\nMalloc failed");
	initialisation(game, argv);
	create_map(game);
	check_error(game);
	create_sprite(game);
	print_sprite(game);
	mlx_key_hook(game->window, read_key, game);
	mlx_hook(game->window, 17, 1L << 17, close_with_cross, game);
	mlx_loop(game->mlx);
	return (0);
}
