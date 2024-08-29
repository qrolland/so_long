/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:51:39 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/19 17:35:12 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_map_height(t_game *game)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		exit_game(game, "Error\nCannot open file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map_height++;
		if (line)
			free (line);
	}
	close(fd);
	if (game->map_height < 3)
		exit_game(game, "Error\nInvalid map size");
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		exit_game(game, "Error\nMalloc failed");
	game->map[game->map_height] = NULL;
}

void	create_map(t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	create_map_height(game);
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		exit_game(game, "Error\nCannot open file");
	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (i != game->map_height - 1)
			line[ft_strlen(line) - 1] = '\0';
		game->map[i] = line;
		i++;
	}
	line = get_next_line(fd);
	close(fd);
}

void	create_sprite(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "Error\nMLX failed");
	game->window_width = game->img_size * game->map_width;
	game->window_height = game->img_size * game->map_height;
	game->window = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "so_long");
	game->sprite_player = mlx_xpm_file_to_image(game->mlx,
			"xpm/ratatouille.xpm", &game->img_size, &game->img_size);
	game->sprite_collectible = mlx_xpm_file_to_image(game->mlx,
			"xpm/fromage.xpm", &game->img_size, &game->img_size);
	game->sprite_end = mlx_xpm_file_to_image(game->mlx,
			"xpm/plaque-egout.xpm", &game->img_size, &game->img_size);
	game->sprite_floor = mlx_xpm_file_to_image(game->mlx,
			"xpm/carrelage.xpm", &game->img_size, &game->img_size);
	game->sprite_wall = mlx_xpm_file_to_image(game->mlx,
			"xpm/mur.xpm", &game->img_size, &game->img_size);
	if (!game->sprite_player || !game->sprite_collectible || !game->sprite_end
		|| !game->sprite_floor || !game->sprite_wall)
		exit_game(game, "Error\n Open file xpm failed");
}

static void	do_sprite(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_collectible, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_end, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_floor, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_wall, IMG_SIZE * j, IMG_SIZE * i);
}

void	print_sprite(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			do_sprite(game, i, j);
	}
}
