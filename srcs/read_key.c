/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:40:46 by qrolland          #+#    #+#             */
/*   Updated: 2023/01/17 18:52:03 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_move(t_game *game, int x, int y)
{
	if (game->map[x][y] == '0' || game->map[x][y] == 'C'
	|| (game->map[x][y] == 'E' && game->collectible == 0))
	{
		if (game->map[x][y] == 'C')
			game->collectible--;
		else if (game->collectible == 0 && game->map[x][y] == 'E')
			exit_game(game, "");
		game->map[game->player_pos_x][game->player_pos_y] = '0';
		game->map[x][y] = 'P';
		game->player_pos_x = x;
		game->player_pos_y = y;
		game->nb_move++;
		ft_putnbr_fd(game->nb_move, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	read_key(int key_code, t_game *game)
{
	if (key_code == W)
		do_move(game, game->player_pos_x - 1, game->player_pos_y);
	else if (key_code == S)
		do_move(game, game->player_pos_x + 1, game->player_pos_y);
	else if (key_code == A)
		do_move(game, game->player_pos_x, game->player_pos_y - 1);
	else if (key_code == D)
		do_move(game, game->player_pos_x, game->player_pos_y + 1);
	else if (key_code == ESC)
		exit_game(game, "");
	print_sprite(game);
	return (1);
}
