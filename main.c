/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:37 by aelkhali          #+#    #+#             */
/*   Updated: 2023/04/28 19:03:14 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(void)
{
	write(1, "Good Bye !\n", 12);
	exit(0);
}

int	mouse_events(int key,int x, int y,  t_game *leet3d)
{
	(void)x;
	(void)y;

	if (key == 1)
		_rotate_player(leet3d, leet3d->rotation_angle);
	else if (key == 2)
		_rotate_player(leet3d, -(leet3d->rotation_angle));
	else if (key == 4)
		_move_back(leet3d);
	else if (key == 5)
		_move_forward(leet3d);
	return (key);
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
	_leet3d_init1(&leet3d);
	mlx_hook(leet3d.win_ptr, 2, 0, &_key_press, &leet3d);
	mlx_loop_hook(leet3d.mlx, _cub3d, &leet3d);
	mlx_hook(leet3d.win_ptr, 4, 0, mouse_events, &leet3d);
	mlx_loop(leet3d.mlx);
	return (EXIT_SUCCESS);
}
