/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:59:19 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/18 16:08:29 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	keydown(int keycode, t_game *game)
{
	if(keycode == 65307) { // esq
		close_game(game);
	}
	return (0);
}

int	render(t_game *game) {
	mlx_put_image_to_window(game->mlx, game->win, game->img.pastel, 0, 0);
	return (0);
}

void	open_images(t_game *game) {
	int pixel = 64;
	game->img.pastel = mlx_xpm_file_to_image(game->mlx, "images/pastel-nata.xpm", &pixel, &pixel);
}

void	destroy_images(t_game *game) {
	mlx_destroy_image(game->mlx, game->img.pastel);
}

void	close_game(t_game *game) {
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
}

// gets the correct map
int	choose_map(char *map)
{
	if(map[3] == '1')
		return (open("../maps/map1.ber", O_RDONLY));
	if(map[3] == '2')
		return (open("../maps/map2.ber", O_RDONLY));
	return (-1);
}

// get map height and width (each block is 64 pixels)
char	**map_info(int fd, char *argv, t_game *game)
{
	char *tmp;
	(void)argv;
	(void)game;

	if(!fd)
		ft_error(3, __FILE__);
	tmp = get_next_line(fd);
	printf("%s", tmp);
	
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	//int pixel = 64;
	(void)argv;
	if(argc != 2)
		ft_error(1, NULL);
	if(ft_strlen(argv[1]) != 4)
		ft_error(3, __FILE__);
	int	fd = choose_map(argv[1]);
	game.matriz = map_info(fd, *argv, &game);



	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1080, 1920, "Hello world!"); // to get the correct wdw size i can do height*64(5*64) meaning the map has 5 blocks of height * 64 cuz one black is 64 pixels
	//game.img->pastel = mlx_xpm_file_to_image(game.mlx, "images/pastel-nata.xpm", &pixel, &pixel);
	mlx_hook(game.win, 2, 1L<<0, keydown, &game);
	open_images(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}
// ./so_long map1