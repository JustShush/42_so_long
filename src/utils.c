/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:13 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/04 11:42:57 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_error(int op, char *file)
{
	if(op == 0 && file == NULL)
		perror("\033[31mError\033[0m");
	if(op == 1) {
		perror("\033[31mProgram has the wrong number of args");
		ft_putstr_fd("\033[0m", 2);
	}
	if(op == 3)
		ft_putstr("\033[31mERROR\033[0m Invalid map name.\n\033[33mHint\033[0m do NOT add .ber at the end");
	exit(1);
}
	/* if(op == 2 && file != NULL) {
		perror("\033[31mError in one");
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\033[0m", 2);
	} */

// initialize the vars
void	vars_init(t_game *game)
{
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