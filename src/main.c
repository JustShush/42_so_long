/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:19 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/09 16:27:58 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_rectangular(t_game *game) // this gives a bunch of memory errors idk how to fix it(need to look more at it)
{
	int len;
	int i;
	int temp;

	i = 0;
	temp = 0;
	len = ft_strlen(game->matriz[0]);
	while (game->matriz[i])
	{
		temp = ft_strlen(game->matriz[i]);
		if (i == game->height - 1)
			temp++;
		//printf("temp: %d..%d, game->matriz[%d]: %s\n", temp, len, i, game->matriz[i]);
		if (temp > len || temp < len)
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int i;
	int last;

	i = 0;
	while (game->matriz[i])
	{
		last = ft_strlen(game->matriz[i]);
		if (game->matriz[i][0] != '1' && game->matriz[i][last] != '1')
		{
			printf("wall error");
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_matriz(t_game *game)
{
	int	y;

	y = 0;
	while (game->matriz && game->matriz[y])
	{
		free(game->matriz[y]);
		y++;
	}
	free(game->matriz);
	game->matriz = NULL;
}

void	map_vfy(t_game *game)
{
	//printf("check_rec: %d", check_rectangular(game));
	if(check_rectangular(game) || check_walls(game))
	{
		free_matriz(game);
		close_game(game);
		ft_error(4, "Invalid map!\nPlease check if the map contents are correct.(ractangular, no extra letters or numbers)");
	}
	//return (0);
}

int	close_x(t_game *game)
{
	close_game(game);
	return (0);
}

char	*vfy_path(char *argv)
{
	char	*path;
	int len;

	len = ft_strlen(argv);
	if (len >= 4 && ft_strcmp(argv + len - 4, ".ber") == 0)
	{
		path = ft_strdup(argv);
		return (path);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_error(1, NULL);
	game.path = vfy_path(argv[1]);
	vars_init(&game);
	if (get_map(&game))
		ft_error(0, __FILE__);
	// check if map is OK
	map_vfy(&game);
	if (open_wdw(&game) != 1)
		ft_error(0, __FILE__);
	open_images(&game);
	mlx_hook(game.wdw, 2, 1L << 0, p_movement, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.wdw, 17, 0, &close_x, &game);
	mlx_loop(game.mlx);
}
// ./so_long map1