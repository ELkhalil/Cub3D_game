/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:01:46 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/15 16:14:05 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//todo : fix rays
void	render_rays(t_game *game)
{
	double	num_rays;
	double	ray_angle;
	int		index;

	ray_angle = game->player.rotation_angle - (game->player.fov / 2);
	num_rays = game->win_width;
	index = -1;
	while (++index < num_rays)
	{
		draw_line(game, game->player.x, game->player.y, \
		game->player.x + cos(ray_angle) * 60, \
		game->player.y + sin(ray_angle) * 60, RED_PIXEL);
		ray_angle += game->player.fov / num_rays;
	}

}
