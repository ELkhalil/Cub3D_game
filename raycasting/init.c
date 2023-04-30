/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:38:55 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/30 19:35:42 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	_leet3d_init2(t_game *leet3d)
{
	if (leet3d->data->map[(int)leet3d->pos.x][(int)leet3d->pos.y] == 'S')
	{
		leet3d->dir.x = 1.0;
		leet3d->dir.y = 0.0;
		leet3d->plane.x = 0.0;
		leet3d->plane.y = -0.66;
	}
	else if (leet3d->data->map[(int)leet3d->pos.x][(int)leet3d->pos.y] == 'E')
	{
		leet3d->dir.x = 0.0;
		leet3d->dir.y = 1.0;
		leet3d->plane.x = 0.66;
		leet3d->plane.y = 0.0;
	}
	else if (leet3d->data->map[(int)leet3d->pos.x][(int)leet3d->pos.y] == 'N')
	{
		leet3d->dir.x = -1.0;
		leet3d->dir.y = 0.0;
		leet3d->plane.x = 0.0;
		leet3d->plane.y = 0.66;
	}
	else if (leet3d->data->map[(int)leet3d->pos.x][(int)leet3d->pos.y] == 'W')
	{
		leet3d->dir.x = 0.0;
		leet3d->dir.y = -1.0;
		leet3d->plane.x = -0.66;
		leet3d->plane.y = 0.0;
	}
}

void	_leet3d_init1(t_game *leet3d)
{
	leet3d->mlx = mlx_init();
	leet3d->window_h = 1200;
	leet3d->window_w = 1200;
	leet3d->i = 0;
	leet3d->win_ptr = mlx_new_window(leet3d->mlx, \
	leet3d->window_w, leet3d->window_h, "leet3D");
	leet3d->img.img = mlx_new_image(leet3d->mlx, \
	leet3d->window_w, leet3d->window_h);
	leet3d->img.addr = (int *)mlx_get_data_addr(leet3d->img.img, \
	&(leet3d->img.bits_per_pixel), &(leet3d->img.line_length), \
	&(leet3d->img.endian));
	leet3d->rotation_angle = 0.2;
	leet3d->move_speed = 0.4;
	leet3d->plane.x = 0.0;
	leet3d->plane.y = 0.66;
	leet3d->pos.x = leet3d->data->p_y;
	leet3d->pos.y = leet3d->data->p_x;
	if (leet3d->data->map[(int)leet3d->pos.x][(int)leet3d->pos.y] == 'S')
	{
		leet3d->dir.x = 1.0;
		leet3d->dir.y = 0.0;
		leet3d->plane.x = 0.0;
		leet3d->plane.y = -0.66;
	}
	_leet3d_init2(leet3d);
}

void	_default_draw_init(t_game	*leet3d)
{
	leet3d->map.x = (int)leet3d->pos.x;
	leet3d->map.y = (int)leet3d->pos.y;
	leet3d->camera_x = 2 * (leet3d->i / (double)(leet3d->window_w)) - 1;
	leet3d->delta_dist.x = sqrt(1 + pow(leet3d->raydir.y, 2) \
		/ pow(leet3d->raydir.x, 2));
	leet3d->delta_dist.y = sqrt(1 + pow(leet3d->raydir.x, 2) \
		/ pow(leet3d->raydir.y, 2));
	leet3d->hit = 0;
	leet3d->raydir.x = leet3d->dir.x + leet3d->plane.x * leet3d->camera_x;
	leet3d->raydir.y = leet3d->dir.y + leet3d->plane.y * leet3d->camera_x;
	if (leet3d->raydir.y < 0)
	{
		leet3d->step.y = -1;
		leet3d->side_dist.y = (leet3d->pos.y - leet3d->map.y) \
		* leet3d->delta_dist.y;
	}
	else
	{
		leet3d->step.y = 1;
		leet3d->side_dist.y = (leet3d->map.y + 1.0 - leet3d->pos.y) \
		* leet3d->delta_dist.y;
	}
	if (leet3d->raydir.x < 0)
	{
		leet3d->step.x = -1;
		leet3d->side_dist.x = (leet3d->pos.x - leet3d->map.x) \
		* leet3d->delta_dist.x;
	}
	else
	{
		leet3d->step.x = 1;
		leet3d->side_dist.x = (leet3d->map.x + 1.0 - leet3d->pos.x) \
		* leet3d->delta_dist.x;
	}
}

void	_load_textures(t_game *leet3d)
{
	leet3d->n = mlx_xpm_file_to_image(leet3d->mlx, leet3d->\
		data->no, &leet3d->texture.width, &leet3d->texture.height);
	leet3d->s = mlx_xpm_file_to_image(leet3d->mlx, leet3d->\
		data->so, &leet3d->texture.width, &leet3d->texture.height);
	leet3d->w = mlx_xpm_file_to_image(leet3d->mlx, leet3d->\
		data->we, &leet3d->texture.width, &leet3d->texture.height);
	leet3d->e = mlx_xpm_file_to_image(leet3d->mlx, leet3d->\
		data->ea, &leet3d->texture.width, &leet3d->texture.height);
	if (!leet3d->n || !leet3d->n || !leet3d->w || !leet3d->e)
		exit(1);
}
