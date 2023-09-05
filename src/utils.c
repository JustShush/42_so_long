/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:13 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/05 17:28:35 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_error(int op, char *arg, t_game *game)
{
	if (op == 0 && arg == NULL)
		perror("\033[31mError\033[0m");
	if (op == 1)
	{
		perror("\033[31mProgram has the wrong number of args");
		ft_putstr_fd("\033[0m", 2);
	}
	if (op == 3)
		ft_putstr("\033[31mERROR\033[0m Invalid map name.");
	if (op == 4)
		ft_printf("\033[31mERROR\033[0m: %s", arg);
	close_game(game);
	exit(1);
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
