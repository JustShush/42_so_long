/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:45:36 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 16:17:07 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// move the player one block to one of the 4 directions
void	move_p(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->wdw, game->img.chao, \
	(game->ploc_x * 64), (game->ploc_y * 64));
	game->ploc_x += x;
	game->ploc_y += y;
	game->moves++;
	printf("x: %d, y: %d, moves: %d\n", game->ploc_x, game->ploc_y, game->moves);
	mlx_put_image_to_window(game->mlx, game->wdw, game->img.zeze, \
	(game->ploc_x * 64), (game->ploc_y * 64));
}

// check the direction the player wants to go
int	p_movement(int key, t_game *game)
{
	if (key == 65307 || key == XK_Escape)
		close_game(game);
	if ((key == XK_w || key == XK_Up) \
	&& game->matriz[game->ploc_y - 1][game->ploc_x] != '1')
		move_p(game, 0, -1);
	if ((key == XK_a || key == XK_Left) \
	&& game->matriz[game->ploc_y][game->ploc_x - 1] != '1')
		move_p(game, -1, 0);
	if ((key == XK_d || key == XK_Right) \
	&& game->matriz[game->ploc_y][game->ploc_x + 1] != '1')
		move_p(game, 1, 0);
	if ((key == XK_s || key == XK_Down) \
	&& game->matriz[game->ploc_y + 1][game->ploc_x] != '1')
		move_p(game, 0, 1);
	return (0);
}