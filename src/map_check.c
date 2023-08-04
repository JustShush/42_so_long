/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:07:31 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/04 15:29:26 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// gets the correct map
int	choose_map(char *map)
{
	if (ft_strcmp(map, "map1") == 0)
		return (open("./maps/map1.ber", O_RDONLY));
	if (ft_strcmp(map, "map2") == 0)
		return (open("./maps/map2.ber", O_RDONLY));
	return (0);
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
char	**get_map(int fd, t_game *game, char *argv)
{
	char	buf;

	if (!fd)
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
	fd = choose_map(argv);
	while (game->i < game->height)
	{
		game->matriz[game->i] = get_next_line(fd);
		game->i++;
		//printf("%s", game->matriz[game->height]);
	}
	game->width = ft_strlen(game->matriz[0]); // first line of the map
	//printf("height: %d\nwidth: %d", game->height, game->width);
	if (check_pec(game))
	{
		return(game->matriz);
	}
	
	return (0);
}