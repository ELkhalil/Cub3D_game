/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:45:32 by aelkhali          #+#    #+#             */
/*   Updated: 2023/05/02 12:33:45 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_pixel(t_img *img, int x, int y, int color)
{
	if (!img)
		return ;
	*(int *)(img->addr + (y * img->line_length / 4) + x) = color;
}

int	get_color(t_game *game, int x, int y)
{
	int	color;

	if (x >= game->data->map_height || y >= game->data->map_width)
		color = GREY_HH;
	else if (game->data->map[x][y] == '1')
		color = GREY_HH;
	else
		color = GREY;
	return (color);
}

int	wach_wall(t_game *game, int x, int y)
{
	if (x >= game->data->map_height || y >= game->data->map_width)
		return (0);
	if (game->data->map[y / MINI_TILE][x / MINI_TILE] == '1')
		return (1);
	return (0);
}
