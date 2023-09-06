/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:44:02 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/06 16:18:47 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	end(t_game *game, int x)
{
	if (x == 0)
	{
		if (game->i == game->ploc_y && game->j == game->ploc_x)
		{
			mlx_put_image_to_window(game->mlx, game->wdw, game->img.chao, \
				(game->j * 64), (game->i * 64));
			game->matriz[game->i][game->j] = '0';
			game->food--;
		}
	}
	if (x == 1)
	{
		if (game->food == 0)
		{
			if (game->i == game->ploc_y && game->j == game->ploc_x)
				close_game(game);
		}
	}
}

int	other_half(t_game *game)
{
	if (game->matriz[game->i][game->j] == 'c')
	{
		end(game, 0);
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.pastel, \
		(game->j * 64), (game->i * 64));
	}
	else if (game->matriz[game->i][game->j] == 'e')
	{
		end(game, 1);
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.barco, \
		(game->j * 64), (game->i * 64));
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.chao, \
		(game->j * 64), (game->i * 64));
	}
	return (0);
}

int	print_img(t_game *game)
{
	if (game->matriz[game->i][game->j] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.parede, \
		(game->j * 64), (game->i * 64));
		return (1);
	}
	else if (game->matriz[game->i][game->j] == 'p')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.chao, \
		(game->j * 64), (game->i * 64));
		return (1);
	}
	else
	{
		if (other_half(game) != 1)
			return (0);
		return (1);
	}
	return (0);
}

// inits all the images
void	open_images(t_game *game)
{
	int	p;

	p = 64;
	game->img.pastel = mlx_xpm_file_to_image(game->mlx, \
	"images/pastel-nata.xpm", &p, &p);
	game->img.parede = mlx_xpm_file_to_image(game->mlx, \
	"images/azuleijo.xpm", &p, &p);
	game->img.chao = mlx_xpm_file_to_image(game->mlx, \
	"images/calcada.xpm", &p, &p);
	game->img.zeze = mlx_xpm_file_to_image(game->mlx, \
	"images/ze.xpm", &p, &p);
	game->img.barco = mlx_xpm_file_to_image(game->mlx, \
	"images/barco.xpm", &p, &p);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.pastel);
	mlx_destroy_image(game->mlx, game->img.parede);
	mlx_destroy_image(game->mlx, game->img.chao);
	mlx_destroy_image(game->mlx, game->img.zeze);
	mlx_destroy_image(game->mlx, game->img.barco);
}
