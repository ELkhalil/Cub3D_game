/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:24:49 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/30 20:41:11 by mmounaji         ###   ########.fr       */
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
	leet3d->plane.y = oldplanx * sin(angle) + leet3d->plane.y * cos(angle);
	rebuild_image(leet3d);
}

void	_move_forward(t_game *leet3d)
{
	if (leet3d->data->map[(int)(leet3d->pos.x + leet3d->dir.x * leet3d->move_speed)][(int)leet3d->pos.y] != WALL)
	{
		leet3d->pos.x += leet3d->dir.x * leet3d->move_speed;
		rebuild_image(leet3d);
	}
	if (leet3d->data->map[(int)leet3d->pos.x][(int)(leet3d->pos.y + leet3d->dir.y * leet3d->move_speed)] != WALL)
	{
		leet3d->pos.y += leet3d->dir.y * leet3d->move_speed;
		rebuild_image(leet3d);
	}
}

void	_move_back(t_game *leet3d)
{
	if (leet3d->data->map[(int)(leet3d->pos.x - leet3d->dir.x * \
	leet3d->move_speed)][(int)leet3d->pos.y] != WALL)
	{
		leet3d->pos.x -= leet3d->dir.x * leet3d->move_speed;
		rebuild_image(leet3d);
	}
	if (leet3d->data->map[(int)leet3d->pos.x][(int)(leet3d->pos.y \
	- leet3d->dir.y * leet3d->move_speed)] != WALL)
	{
		leet3d->pos.y -= leet3d->dir.y * leet3d->move_speed;
		rebuild_image(leet3d);
	}
}

void	_move_right(t_game *leet3d)
{
	if (leet3d->data->map[(int)(leet3d->pos.x - leet3d->dir.x + leet3d->plane.x)][(int)leet3d->pos.y] != WALL)
	{
		leet3d->pos.x += leet3d->plane.x * leet3d->move_speed;
		rebuild_image(leet3d);
	}
	if (leet3d->data->map[(int)leet3d->pos.x][(int)(leet3d->pos.y + leet3d->dir.y + leet3d->plane.y)] != WALL)
	{
		leet3d->pos.y += leet3d->plane.y * leet3d->move_speed;
		rebuild_image(leet3d);
	}
}

void	_move_left(t_game *leet3d)
{
	if (leet3d->data->map[(int)(leet3d->pos.x - leet3d->dir.x - leet3d->plane.x)][(int)(leet3d->pos.y)] != WALL)
	{
		leet3d->pos.x -= leet3d->plane.x * leet3d->move_speed;
		rebuild_image(leet3d);
	}
	if (leet3d->data->map[(int)leet3d->pos.x][(int)(leet3d->pos.y - leet3d->dir.y - leet3d->plane.y)] != WALL)
	{
		leet3d->pos.y -= leet3d->plane.y * leet3d->move_speed;
		rebuild_image(leet3d);
	}
}
