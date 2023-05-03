/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:37 by aelkhali          #+#    #+#             */
/*   Updated: 2023/05/02 20:49:23 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(void)
{
	write(1, "Good Bye !\n", 12);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_game	leet3d;

	if (ac == 1 || ac > 2 || ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
		return (ft_error("Invalid arguments\n"), EXIT_FAILURE);
	data = parse_game_data(av[1]);
	if (!data)
		return (ft_error("while Setting Game data\n"), EXIT_FAILURE);
	leet3d.data = data;
	leet3d.mlx = mlx_init();
	leet3d.window_h = 1200;
	leet3d.window_w = 1200;
	leet3d.win_ptr = mlx_new_window(leet3d.mlx, \
	leet3d.window_w, leet3d.window_h, "leet3D");
	leet3d.img.img = mlx_new_image(leet3d.mlx, \
	leet3d.window_w, leet3d.window_h);
	_leet3d_init1(&leet3d);
	_load_textures(&leet3d);
	mlx_hook(leet3d.win_ptr, 2, 0, &_key_press, &leet3d);
	mlx_hook(leet3d.win_ptr, 17, 0, &close_game, &leet3d);
	mlx_loop_hook(leet3d.mlx, _cub3d, &leet3d);
	mlx_hook(leet3d.win_ptr, 4, 0, &_mouse_events, &leet3d);
	mlx_loop(leet3d.mlx);
	return (EXIT_SUCCESS);
}
