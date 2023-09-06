/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:19 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/06 14:01:04 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_matriz(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->matriz[i++]);
	}
	free(game->matriz);
}

int	close_x(t_game *game)
{
	close_game(game);
	return (0);
}

char	*vfy_path(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len >= 4 && ft_strcmp(argv + len - 4, ".ber") == 0)
	{
		return (argv);
	}
	return (NULL);
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
	mlx_put_image_to_window(game->mlx, game->wdw, game->img.zeze, \
	(game->ploc_x * 64), (game->ploc_y * 64));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_error(1, NULL, &game);
	game.path = vfy_path(argv[1]);
	if (!game.path)
		ft_error(3, __FILE__, &game);
	vars_init(&game);
	if (get_map(&game))
		ft_error(0, __FILE__, &game);
	map_vfy(&game);
	game.mlx = mlx_init();
	open_images(&game);
	if (open_wdw(&game) != 1)
		ft_error(2, __FILE__, &game);
	mlx_hook(game.wdw, 2, 1L << 0, p_movement, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.wdw, 17, 0, &close_x, &game);
	mlx_loop(game.mlx);
}
// ./so_long map1