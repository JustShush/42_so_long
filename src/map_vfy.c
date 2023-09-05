/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vfy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:50:41 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/05 16:49:46 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

int	check_walls(t_game *game)
{
	int	i;
	int	last;

	i = 0;
	while (i < game->height)
	{
		last = ft_strlen(game->matriz[i]);
		if (game->matriz[i][0] != '1' || game->matriz[i][last - 2] != '1')
		{
			ft_printf("wall error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	map_vfy(t_game *game)
{
	if (check_rectangular(game) || check_walls(game) || check_pec(game))
	{
		ft_error(4, \
		"Invalid map!\nPlease check if the map contents are correct.", game);
	}
}
