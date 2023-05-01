/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:13:35 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/30 19:46:15 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	_drawing_ceiling(t_game *leet3d)
{
	int	i;

	i = leet3d->draw_end;
	while (++i < leet3d->window_h)
	{
		leet3d->img.addr[i * leet3d->window_w + leet3d->i] = get_rgb_color(\
		leet3d->data->f[0], leet3d->data->f[1], leet3d->data->f[2]);
	}	
}

void	_drawing_floor(t_game *leet3d)
{
	int	i;

	i = -1;
	while (++i < leet3d->draw_start)
	{
		leet3d->img.addr[i * leet3d->window_w + leet3d->i] = get_rgb_color(\
		leet3d->data->c[0], leet3d->data->c[1], leet3d->data->c[2]);
	}
}

void	_setup_textures(t_game *leet3d)
{
	if (leet3d->side == 0 && leet3d->step.x == -1)
		leet3d->texture.img = leet3d->n;
	else if (leet3d->side == 0 && leet3d->step.x == 1)
		leet3d->texture.img = leet3d->s;
	else if (leet3d->side == 1 && leet3d->step.y == -1)
		leet3d->texture.img = leet3d->w;
	else if (leet3d->side == 1 && leet3d->step.y == 1)
		leet3d->texture.img = leet3d->e;
	leet3d->texture.addr = (int *)mlx_get_data_addr(leet3d->texture.img, \
		&leet3d->texture.bits_per_pixel, &leet3d->texture.line_length, \
		&leet3d->texture.endian);
	if (leet3d->side == 0)
		leet3d->wallx = leet3d->pos.y + leet3d->perp_wall_dist * \
		leet3d->raydir.y;
	else
		leet3d->wallx = leet3d->pos.x + leet3d->perp_wall_dist * \
		leet3d->raydir.x;
	leet3d->wallx -= floor(leet3d->wallx);
	leet3d->_texturex = (int)(leet3d->wallx * (double)(leet3d->texture.width));
	if (leet3d->side == 0 && leet3d->raydir.x > 0)
		leet3d->_texturex = leet3d->texture.width - leet3d->_texturex - 1;
	if (leet3d->side == 1 && leet3d->raydir.x < 0)
		leet3d->_texturex = leet3d->texture.width - leet3d->_texturex - 1;
	leet3d->tex_step = 1.0 * leet3d->texture.height / leet3d->line_height;
	leet3d->tex_pos = (leet3d->draw_start - leet3d->window_h \
		/ 2 + leet3d->line_height / 2) * leet3d->tex_step;
}

void	_drawing_textures(t_game *leet3d)
{
	int	y;

	y = leet3d->draw_start;
	while (y < leet3d->draw_end)
	{
		leet3d->_texturey = (int)leet3d->tex_pos & \
		(leet3d->texture.height - 1);
		leet3d->tex_pos += leet3d->tex_step;
		leet3d->color = leet3d->texture.addr[leet3d->texture.height \
		*leet3d->_texturey + leet3d->_texturex];
		leet3d->img.addr[y * (leet3d->window_w) + (leet3d->i)] = leet3d->color;
		y++;
	}
}
