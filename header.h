/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:03:54 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/04 12:38:41 by dimarque         ###   ########.fr       */
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
	void *parede;
	void *chao;
	void *zeze;
	void *barco;
}	t_image;

typedef struct	s_vars {
	void	*mlx;
	void	*wdw;
	char	**matriz;
	int		height;
	int		width;
	int		temp;
	int		player;
	int		food;
	int		exit;
	int		i;
	int		j;
	int		eloc_x;
	int		eloc_y;
	int		ploc_x;
	int		ploc_y;
	int		pp_x;
	int		pp_y;
	t_image img;
}	t_game;

// in lib.c
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
// ----------------------------

// in lib1.c

int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
// ----------------------------

void	close_game(t_game *vars);

// in map_check.c

int		choose_map(char *map);
char	**get_map(int fd, t_game *game, char *argv);
// -----------------------------

// in utils.c

void	ft_error(int op, char *file);
void	vars_init(t_game *game);
// -----------------------------

// in start_wdw.c

int	open_wdw(t_game *game);
// -----------------------------

#endif