/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:01:46 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/17 17:12:27 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_ray	_cast_ray(t_game *game, double ray_angle)
{
	t_ray		ray;
	t_vector	horz_touch;
	t_vector	vert_touch;

	ray.angle = ray_angle;
	horz_touch = horizontal_(game, ray.angle);
	vert_touch = vertical_(game, ray.angle);
	draw_line(game, game->player.x ,game->player.y, horz_touch.x, horz_touch.y, RED_PIXEL);
	return (ray);

}

void	render_rays(t_game *game)
{
	double	num_rays;
	double	ray_angle;
	int		index;

	ray_angle = game->player.rotation_angle - \
	(game->player.fov / 2);
	num_rays = game->win_width;
	index = -1;
	while (++index < num_rays)
	{
		game->player.rays[index] = _cast_ray(game, angle(ray_angle));
		ray_angle += (game->player.fov / num_rays);
	}
}
