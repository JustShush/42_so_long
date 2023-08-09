/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:07:31 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/09 16:35:39 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	fd_map(char *map)
{
	return(open(map, O_RDONLY));
}

void	pec_ifs(t_game *game)
{
	if (game->matriz[game->i][game->j] == 'C')
	{
		game->food++;
	}
	if (game->matriz[game->i][game->j] == 'E')
	{
		game->exit++;
		game->eloc_y = game->i;
		game->eloc_x = game->j;
	}
	if (game->matriz[game->i][game->j] == 'P')
	{
		game->player++;
		game->ploc_y = game->i;
		game->ploc_x = game->j;
	}
}

// checks the player, exit and the collectables(foods)
int	check_pec(t_game *game)
{
	game->i = 0;
	while (game->i < game->height)
	{
		game->j = 0;
		while (game->j < game->width)
		{
			pec_ifs(game);
			game->j++;
		}
		game->i++;
	}
	if (game->player != 1 || game->food == 0 || game->exit != 1)
		return (0);
	return (1);
}

// get map height and width (each block is 64 pixels)
int	get_map(t_game *game)
{
	char	buf;
	int fd;

	fd = fd_map(game->path);
	if (!game->path)
		ft_error(3, __FILE__);
	buf = '\0';
	while (read(fd, &buf, 1))
		if (buf == '\n')
			game->height++;
	game->height++;
	close(fd);
	printf("game->height: %d\n", game->height);
	game->matriz = malloc(sizeof(char *) * (game->height));
	if (!game->matriz)
		ft_error(0, __FILE__);
	game->i = 0;
	fd = fd_map(game->path);
	while (game->i < game->height)
	{
		game->matriz[game->i] = get_next_line(fd);
		game->i++;
	}
	close(fd);
	game->width = (ft_strlen(game->matriz[0]) - 1);
	if (check_pec(game))
	{
		return(1);
	}
	return (0);
}