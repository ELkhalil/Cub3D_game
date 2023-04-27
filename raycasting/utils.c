/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:05 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/25 14:17:56 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	angle(double ray_angle)
{
	ray_angle = remainder(ray_angle, PI * 2);
	if (ray_angle < 0)
		ray_angle += PI * 2;
	return (ray_angle);
}
