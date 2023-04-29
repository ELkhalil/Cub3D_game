/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:42:06 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/29 11:44:10 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	rebuild_image(t_game *leet3d)
{
	mlx_clear_window(leet3d->mlx, leet3d->win_ptr);
	mlx_destroy_image(leet3d->mlx, leet3d->img.img);
	leet3d->img.img = mlx_new_image(leet3d->mlx, leet3d->window_w, \
	leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img, \
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->i = 0;
	_cub3d(leet3d);
}

int	_key_press(int key, t_game *leet3d)
{
	if (key == 53 || key == 12)
		close_game();
	if (key == RIGHT_R)
		_rotate_player(leet3d, -(leet3d->rotation_angle));
	if (key == LEFT_R)
		_rotate_player(leet3d, leet3d->rotation_angle);
	if (key == UP_M)
		_move_forward(leet3d);
	if (key == DOWN_M)
		_move_back(leet3d);
	if (key == RIGHT_M)
		_move_right(leet3d);
	if (key == LEFT_M)
		_move_left(leet3d);
	else
		return (1);
	return (0);
}

int	_mouse_events(int key, int x, int y, t_game *leet3d)
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
