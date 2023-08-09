/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:10:25 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 12:41:44 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	open_wdw(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	game->wdw = mlx_new_window(game->mlx, (game->width * 64), (game->height * 64), "so_long!");
	if (!(game->wdw))
	{
		free (game->mlx);
		return (0);
	}
	game->pp_x = (game->ploc_x * 64);
	game->pp_y = (game->ploc_y * 64);
	return (1);
}

void	close_game(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->wdw);
	exit(0);
}