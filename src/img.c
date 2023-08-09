/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:44:02 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 11:50:04 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	other_half(t_game *game)
{
	if (game->matriz[game->i][game->j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.pastel, \
		(game->j * 64), (game->i * 64));
		return (1);
	}
	if (game->matriz[game->i][game->j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.barco, \
		(game->j * 64), (game->i * 64));
		return (1);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.chao, \
		(game->j * 64), (game->i * 64));
		return (1);
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
	if (game->matriz[game->i][game->j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.zeze, \
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

int	render(t_game *game)
{
	game->i = 0;
	while (game->i < game->height)
	{
		game->j = 0;
		while (game->j < game->width)
		{
			print_img(game);
			game->j++;
		}
		game->i++;
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
