/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:01:46 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/16 17:39:07 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	facing(double angle, t_facing facing)
{
	if (facing == UP)
		return (!(angle > 0 && angle < PI));
	else if (facing == DOWN)
		return (angle > 0 && angle < PI);
	else if (facing == RIGHT)
		return (!(angle > 0.5 * PI && angle < 1.5 * PI));
	else if (facing == LEFT)
		return (angle > 0.5 * PI && angle < 1.5 * PI);
	return (-1);
}

t_vector	set_xystep(double ray_angle)
{
	t_vector	step;

	step.y = 32;
	if (facing(ray_angle, UP))
		step.y *= -1;
	step.x = 32 / tan(ray_angle);
	if (facing(ray_angle, LEFT) && step.x > 0)
		step.x *= -1;
	if (facing(ray_angle, RIGHT) && step.x < 0)
		step.x *= -1;
	return (step);
}

t_vector	set_intercept(t_player player, double ray_angle)
{
	t_vector	intercept;

	intercept.y = floor(player.y / 32) * 32;
	if (facing(ray_angle, DOWN))
		intercept.y += 32;
	intercept.x = player.x + ((intercept.y - \
	player.y) / tan(ray_angle));
	return (intercept);
}


double	angle(double angle)
{
	angle = remainder(angle, PI * 2);
	if (angle < 0)
		angle += PI * 2;
	return (angle);
}

t_ray	cast_one_ray(t_game *game, double ray_angle)
{
	t_ray		ray;
	t_vector	step;
	t_vector	intercept;
	t_vector	horz_touch;

	intercept = set_intercept(game->player, ray_angle);
	step = set_xystep(ray_angle);
	horz_touch.x = intercept.x;
	horz_touch.y = intercept.y;
	if (facing(ray_angle, UP))
		horz_touch.y--;
	while (1)
	{
		if (check_wall(game, horz_touch.x, horz_touch.y))
		{
			ray.wall_hit.x = horz_touch.x;
			ray.wall_hit.y = horz_touch.y;
			draw_line(game, game->player.x, game->player.y, \
			ray.wall_hit.x, ray.wall_hit.y, RED_PIXEL);
			break ;
		}
		else
		{
			horz_touch.x += step.x;
			horz_touch.y += step.y;
		}
	}
	return (ray);
}

void	render_rays(t_game *game)
{
	double	num_rays;
	double	ray_angle;
	int		index;

	ray_angle = angle(game->player.rotation_angle - \
	(game->player.fov / 2));
	num_rays = game->win_width;
	index = -1;
	while (++index < 1)
	{
		game->player.rays[index] = cast_one_ray(game, ray_angle);
		ray_angle += angle(game->player.fov / num_rays);
	}
}
