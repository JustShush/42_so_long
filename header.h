/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:03:54 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/09 16:34:26 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../mlx_linux/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

// keyboard control
# include <X11/X.h>
# include <X11/keysym.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_image {
	void	*pastel;
	void	*parede;
	void	*chao;
	void	*zeze;
	void	*barco;
}	t_image;

typedef struct s_vars {
	void	*mlx;
	void	*wdw;
	char	**matriz;
	char	*path;
	int		moves;
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
	t_image	img;
}	t_game;

// in img.c

int		render(t_game *game);
void	open_images(t_game *game);
void	destroy_images(t_game *game);
// ----------------------------

// in lib.c
//size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
// ----------------------------

// in lib1.c

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
// ----------------------------

void	free_matriz(t_game *game);

// in map_check.c

int		get_map(t_game *game);
// ----------------------------

// in movements.c

int	p_movement(int key, t_game *game);
// ----------------------------

// in utils.c

void	ft_error(int op, char *file);
void	vars_init(t_game *game);
// ----------------------------

// in wdw.c

int		open_wdw(t_game *game);
void	close_game(t_game *game);
// ----------------------------

#endif