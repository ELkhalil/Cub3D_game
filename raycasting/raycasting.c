/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:36:40 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/30 13:44:29 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	get_rgb_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

int	_raycaster(t_game *leet3d)
{
	while (leet3d->hit == 0)
	{
		if (leet3d->side_dist.x < leet3d->side_dist.y)
		{
			leet3d->side_dist.x += leet3d->delta_dist.x;
			leet3d->map.x += leet3d->step.x;
			leet3d->side = 0;
		}
		else
		{
			leet3d->side_dist.y += leet3d->delta_dist.y;
			leet3d->map.y += leet3d->step.y;
			leet3d->side = 1;
		}
		if (!_out_range(leet3d->data->map, leet3d->map.y, leet3d->map.x) && \
		leet3d->data->map[(int)leet3d->map.x][(int)leet3d->map.y] == WALL)
			leet3d->hit = 1;
	}
	if (leet3d->side == 0)
		leet3d->perp_wall_dist = fabs((leet3d->map.x - leet3d->pos.x + (1 - \
		leet3d->step.x) / 2) / leet3d->raydir.x);
	else
		leet3d->perp_wall_dist = fabs((leet3d->map.y - leet3d->pos.y + (1 - \
		leet3d->step.y) / 2) / leet3d->raydir.y);
	return (EXIT_SUCCESS);
}

void	_distance_setup(t_game *leet3d)
{
	if (!leet3d->perp_wall_dist)
	{
		leet3d->perp_wall_dist = 1;
	}
	leet3d->line_height = (int)(leet3d->window_h / leet3d->perp_wall_dist);
	leet3d->draw_start = -leet3d->line_height / 2 + leet3d->window_h / 2;
	if (leet3d->draw_start < 0)
		leet3d->draw_start = 0;
	leet3d->draw_end = leet3d->line_height / 2 + leet3d->window_h / 2;
	if (leet3d->draw_end >= leet3d->window_h)
		leet3d->draw_end = leet3d->window_h - 1;
}

int	_cub3d(void *game)
{
	t_game	*leet3d;

	leet3d = game;
	while (leet3d->i < leet3d->window_w)
	{
		_default_draw_init(leet3d);
		_raycaster(leet3d);
		_distance_setup(leet3d);
		_drawing_floor(leet3d);
		_drawing_ceiling(leet3d);
		_setup_textures(leet3d);
		_drawing_textures(leet3d);
		leet3d->i++;
	}
	mlx_put_image_to_window(leet3d->mlx, leet3d->win_ptr, \
	leet3d->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
