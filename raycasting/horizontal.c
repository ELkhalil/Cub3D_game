/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:32:54 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/17 16:34:12 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
	printf("%f %f\n", step.x, step.y);
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
	printf("**%f %f***\n", intercept.x, intercept.y);
	return (intercept);
}

t_vector	horizontal_(t_game *game, double ray_angle)
{
	t_vector	step;
	t_vector	horz_touch;
	int			flag;

	flag = 0;
	if (facing(ray_angle, UP))
		flag = -1;
	horz_touch = set_intercept(game->player, ray_angle);
	step = set_xystep(ray_angle);
	if (facing(ray_angle, UP))
		horz_touch.y--;
	while (1)
	{
		if (check_wall(game, horz_touch.x, horz_touch.y + flag) == 1)
		{
			return (horz_touch);
		}
		else
		{
			horz_touch.x += step.x;
			horz_touch.y += step.y;
		}
	}
	return (horz_touch);
}
