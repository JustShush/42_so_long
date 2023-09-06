/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:13 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/06 16:21:20 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_error(int op, char *arg, t_game *game)
{
	if (op == 0 && arg == NULL)
	{
		perror("\033[31mError\033[0m");
		free_matriz(game);
		free(game->mlx);
	}
	if (op == 1)
	{
		perror("\033[31mProgram has the wrong number of args");
		ft_putstr_fd("\033[0m", 2);
	}
	if (op == 2)
	{
		ft_printf("\033[31mERROR\033[0m: %s", arg);
		close_game(game);
	}
	if (op == 3)
		ft_putstr("\033[31mERROR\033[0m Invalid map name.");
	if (op == 4)
		ft_printf("\033[31mERROR\033[0m: %s", arg);
	exit(0);
}

// initialize the vars
void	vars_init(t_game *game)
{
	game->moves = 0;
	game->height = 0;
	game->width = 0;
	game->temp = 0;
	game->player = 0;
	game->food = 0;
	game->exit = 0;
	game->i = 0;
	game->j = 0;
	game->eloc_x = 0;
	game->eloc_y = 0;
	game->ploc_x = 0;
	game->ploc_y = 0;
}

void	free_map(t_floodfill *floodfill, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(floodfill->map[i++]);
	}
	free(floodfill->map);
}

void	map_vfy(t_game *game)
{
	if (check_rectangular(game) || check_walls(game) || check_pec(game) \
	|| check_fl(game) || ft_flood(game))
	{
		ft_error(4, \
		"Invalid map!\nPlease check if the map contents are correct.\n", game);
	}
}
