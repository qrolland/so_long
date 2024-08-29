/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:28:34 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/17 19:02:54 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# define W			119
# define A			97
# define S			115
# define D			100
# define ESC		65307
# define IMG_SIZE	50

typedef struct s_game
{
	char	**map;
	char	**visited;
	char	*filename;
	int		player;
	int		collectible;
	int		end;
	int		nb_move;
	int		player_pos_x;
	int		player_pos_y;
	int		img_size;
	int		map_width;
	int		map_height;
	int		window_width;
	int		window_height;
	void	*sprite_player;
	void	*sprite_collectible;
	void	*sprite_end;
	void	*sprite_floor;
	void	*sprite_wall;
	void	*mlx;
	void	*window;
}	t_game;

void	exit_game(t_game *game, char *error);
void	create_map(t_game *game);
void	create_sprite(t_game *game);
void	print_sprite(t_game *game);
void	check_rectangle(t_game *game);
void	check_walls(t_game *game);
void	check_elements(t_game *game);
int		read_key(int key_code, t_game *game);
void	check_path(t_game *game);
int		check_arg_ext(char **argv);
int		close_with_cross(t_game *game);

#endif