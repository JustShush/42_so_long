/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vfy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:50:41 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/06 16:21:03 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	flood_fill(t_floodfill *floodfill, int x, int y, t_game *game)
{
	if (game->matriz[y][x] == '1' || game->matriz[y][x] == 'F')
		return ;
	if (game->matriz[y][x] == 'E')
	{
		if (floodfill->exits)
			floodfill->exits--;
		game->matriz[y][x] = 'e';
		return ;
	}
	if (game->matriz[y][x] == 'C')
	{
		game->matriz[y][x] = 'c';
		floodfill->collectibles--;
	}
	if (game->matriz[y][x] == '0')
		game->matriz[y][x] = 'F';
	flood_fill(floodfill, x + 1, y, game);
	flood_fill(floodfill, x - 1, y, game);
	flood_fill(floodfill, x, y + 1, game);
	flood_fill(floodfill, x, y - 1, game);
}

int	ft_flood(t_game *game)
{
	t_floodfill	floodfill;

	floodfill.collectibles = game->food;
	floodfill.exits = game->exit;
	flood_fill(&floodfill, game->ploc_x, game->ploc_y, game);
	if (floodfill.collectibles || floodfill.exits)
		return (1);
	return (0);
}

int	check_walls(t_game *game)
{
	int	i;
	int	last;

	i = 0;
	while (i < game->height)
	{
		last = ft_strlen(game->matriz[i]);
		if (i == (game->height - 1))
			last = ft_strlen(game->matriz[i]) + 1;
		if (game->matriz[i][0] != '1' || game->matriz[i][last - 2] != '1')
		{
			ft_printf("wall error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_rectangular(t_game *game)
{
	int	len;
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	len = ft_strlen(game->matriz[0]);
	while (i < (game->height))
	{
		temp = ft_strlen(game->matriz[i]);
		if (i == game->height - 1)
			temp++;
		if (temp != len)
			return (1);
		i++;
	}
	return (0);
}

int	check_fl(t_game *game)
{
	int	len;
	int	i;

	len = ft_strlen(game->matriz[0]);
	i = 0;
	while (i < len - 1)
	{
		if (game->matriz[0][i] != '1')
			return (1);
		i++;
	}
	len = ft_strlen(game->matriz[game->height - 1]);
	i = 0;
	while (i < len - 1)
	{
		if (game->matriz[game->height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}
