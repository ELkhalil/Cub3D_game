/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:45:32 by aelkhali          #+#    #+#             */
/*   Updated: 2023/05/02 18:03:29 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (!img)
		return ;
	offset = (y * img->line_length / 4) + x;
	*(int *)(img->addr + offset) = color;
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
