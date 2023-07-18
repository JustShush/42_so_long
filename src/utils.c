/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:13 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/18 14:12:52 by dimarque         ###   ########.fr       */
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
		ft_putstr("\033[31mERROR\033[0m do NOT add .ber at the end, or \033[31mInvalid\033[0m map name");
	exit(0);
}
	/* if(op == 2 && file != NULL) {
		perror("\033[31mError in one");
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\033[0m", 2);
	} */
