/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:19 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/04 15:19:27 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	keydown(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	/* else if (keycode == 119 || keycode == 65362)
		ft_move_player_y(game, -1);
	else if (keycode == 100 || keycode == 65363)
		ft_move_player_x(game, 1);
	else if (keycode == 115 || keycode == 65364)
		ft_move_player_y(game, 1);
	else if (keycode == 97 || keycode == 65361)
		ft_move_player_x(game, -1); */
	return (0);
}

int	print_img(t_game *game)
{
	if (game->matriz[game->i][game->j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.barco, (game->j * 64), (game->i * 64));
		return (1);
	}
	else {
		mlx_put_image_to_window(game->mlx, game->wdw, game->img.chao, (game->j * 64), (game->i * 64));
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
			if (print_img(game) != 1)
				ft_error(0, __FILE__);
			game->j++;
		}
		game->i++;
	}
	mlx_put_image_to_window(game->mlx, game->wdw, game->img.pastel, 0, 0);
	return (0);
}

void	open_images(t_game *game)
{
	int		pixel;
	char	*path;
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;

	pixel = 64;
	path = "images/pastel-nata.xpm";
	path1 = "images/azuleijo.xpm";
	path2 = "images/calcada.xpm";
	path3 = "images/ze.xpm";
	path4 = "images/barco.xpm";
	game->img.pastel = mlx_xpm_file_to_image(game->mlx, path, &pixel, &pixel);
	game->img.parede = mlx_xpm_file_to_image(game->mlx, path1, &pixel, &pixel);
	game->img.chao = mlx_xpm_file_to_image(game->mlx, path2, &pixel, &pixel);
	game->img.zeze = mlx_xpm_file_to_image(game->mlx, path3, &pixel, &pixel);
	game->img.barco = mlx_xpm_file_to_image(game->mlx, path4, &pixel, &pixel);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.pastel);
}

void	close_game(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->wdw);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	game;

	(void)argv;
	if (argc != 2)
		ft_error(1, NULL);
	if (ft_strlen(argv[1]) != 4)
		ft_error(3, __FILE__);
	fd = choose_map(argv[1]);
	//printf("%d", fd);
	vars_init(&game);
	game.matriz = get_map(fd, &game, argv[1]);
	//printf("%c\n", argv[1][3]);
	if (open_wdw(&game) != 1)
		ft_error(0, __FILE__);
	mlx_hook(game.wdw, 2, 1L << 0, keydown, &game);
	open_images(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	close(fd);
}
// to get the correct wdw size i can do height*64(5*64) 
// meaning the map has 5 blocks of height * 64 cuz one block is 64 pixels
// ./so_long map1