/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:42:07 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/17 17:07:25 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vector	set_v_intercept(t_player player, double ray_angle)
{
	t_vector	i;

	i.x = floor(player.x / 32) * 32;
	if (facing(ray_angle, RIGHT))
		i.x += 32;
	i.y = player.y + (i.x - player.x) * tan(ray_angle);
	return (i);
}

t_vector	set_v_step(double ray_angle)
{
	t_vector	step;

	step.x = 32;
	if (facing(ray_angle, LEFT))
		step.x *= -1;
	step.y = 32 * tan(ray_angle);
	if (facing(ray_angle, UP) && step.y > 0)
		step.y *= -1;
	if (facing(ray_angle, DOWN) && step.y < 0)
		step.y *= -1;
	return (step);
}

t_vector	vertical_(t_game *game, double ray_angle)
{
	t_vector	step;
	t_vector	vert_touch;
	int			flag;

	flag = 0;
	if (facing(ray_angle, LEFT))
		flag = -1;
	step = set_v_step(ray_angle);
	vert_touch = set_v_intercept(game->player, ray_angle);
	while (1)
	{
		if (check_wall(game, vert_touch.x, vert_touch.y + flag) == 1)
		{
			return (vert_touch);
		}
		else
		{
			vert_touch.x += step.x;
			vert_touch.y += step.y;
		}
	}
	return (vert_touch);
}