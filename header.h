/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:03:54 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/18 15:39:49 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../mlx_linux/mlx.h"
# include "GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_image {

	void *pastel;
	void *zero;
	void *one;

} t_image;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**matriz;
	t_image img;
}				t_game;

// in lib.c
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
// ----------------------------

void	close_game(t_game *vars);

// in utils.c
void	ft_error(int op, char *file);
// -----------------------------

#endif