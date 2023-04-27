/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:24:49 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/27 15:26:53 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	_rotate_player(t_game *leet3d, double angle)
{
	double	olddirx;
	double	oldplanx;

	oldplanx = leet3d->plane.x;
	olddirx = leet3d->dir.x;
	leet3d->dir.x = leet3d->dir.x * cos(angle) - \
		leet3d->dir.y * sin(angle);
	leet3d->dir.y = olddirx * sin(angle) + leet3d->dir.y * cos(angle);
	leet3d->plane.x = leet3d->plane.x * cos(angle) - \
		leet3d->plane.y * sin(angle);
	leet3d->plane.y = oldplanx * sin(angle) +leet3d->plane.y * cos(angle);
	mlx_destroy_image(leet3d->mlx, leet3d->img.img);
	leet3d->img.img = mlx_new_image(leet3d->mlx, leet3d->window_w, \
	leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img,\
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->i = 0;
	_cub3d(leet3d);
}

void	_move_forward(t_game *leet3d)
{
	int	x;
	int	y;

	x = (int)(leet3d->pos.x + leet3d->dir.x);
	y = (int)(leet3d->pos.y + leet3d->dir.y);
	if (leet3d->data->map[x][y] == EMPTY)
	{
		leet3d->pos.x += leet3d->dir.x * leet3d->move_speed;
		leet3d->pos.y += leet3d->dir.y * leet3d->move_speed;
	}
	mlx_destroy_image(leet3d->mlx, leet3d->img.img);
	leet3d->img.img = mlx_new_image(leet3d->mlx, leet3d->window_w, \
	leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img,\
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->i = 0;
	_cub3d(leet3d);
}

void	_move_back(t_game *leet3d)
{
	int	x;
	int	y;

	x = (int)(leet3d->pos.x - leet3d->dir.x);
	y = (int)(leet3d->pos.y - leet3d->dir.y);
	if (leet3d->data->map[x][y] == EMPTY)
	{
		leet3d->pos.x -= leet3d->dir.x * leet3d->move_speed;
		leet3d->pos.y -= leet3d->dir.y * leet3d->move_speed;
	}
	mlx_destroy_image(leet3d->mlx, leet3d->img.img);
	leet3d->img.img = mlx_new_image(leet3d->mlx, leet3d->window_w, \
	leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img, \
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->i = 0;
	_cub3d(leet3d);
}

void	_move_right(t_game *leet3d)
{
	int	x;
	int	y;

	x = (int)leet3d->pos.x;
	y = (int)(leet3d->pos.y + leet3d->dir.y + leet3d->plane.y);
	if (leet3d->data->map[x][y] == EMPTY)
	{
		leet3d->pos.x += leet3d->plane.x * leet3d->move_speed;
		leet3d->pos.y += leet3d->plane.y * leet3d->move_speed;
	}
	mlx_destroy_image(leet3d->mlx, leet3d->img.img);
	leet3d->img.img = mlx_new_image(leet3d->mlx, leet3d->window_w, \
	leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img,\
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->i = 0;
	_cub3d(leet3d);
}

void	_move_left(t_game *leet3d)
{
	int	x;
	int	y;

	x = (int)leet3d->pos.x;
	y = (int)(leet3d->pos.y + leet3d->dir.y - leet3d->plane.y);
	if (leet3d->data->map[x][y] == EMPTY)
	{
		leet3d->pos.x -= leet3d->plane.x * leet3d->move_speed;
		leet3d->pos.y -= leet3d->plane.y * leet3d->move_speed;
	}
	mlx_destroy_image(leet3d->mlx, leet3d->img.img);
	leet3d->img.img = mlx_new_image(leet3d->mlx, leet3d->window_w, \
	leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img,\
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->i = 0;
	_cub3d(leet3d);
}

