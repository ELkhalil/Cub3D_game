/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:05 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/17 14:51:32 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	facing(double angle, t_facing facing)
{
	if (facing == RIGHT)
		return (angle >= 1.5 * PI || angle <= 0.5 * PI);
	else if (facing == LEFT)
		return (angle > 0.5 * PI && angle < 1.5 * PI);
	else if (facing == UP)
		return (angle >= PI);
	else if (facing == DOWN)
		return (angle < PI);
	return (-1);
}

double	angle(double ray_angle)
{
	ray_angle = remainder(ray_angle, PI * 2);
	if (ray_angle < 0)
		ray_angle += PI * 2;
	return (ray_angle);
}
