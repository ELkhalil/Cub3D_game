/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:40:49 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/16 15:48:45 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int draw_line(t_game *game, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

int	get_rgb_color(t_rgb *rgb)
{
	return ((rgb->red << 16) + (rgb->green << 8) + rgb->blue);
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	*draw_image(t_game *game, int color, int w, int h)
{
	int	pixel;

	game->img.img = mlx_new_image(game->mlx, w, h);
	if (!game->img.img)
		exit(1);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (game->img.bits_per_pixel != 32)
		color = mlx_get_color_value(game->mlx, color);
	for (int y = 0; y < w; ++y)
	for (int x = 0; x < h; ++x)
	{
		pixel = (y * game->img.line_length) + (x * 4);

    	if (game->img.endian == 1)
    	{
       	 	game->img.addr[pixel + 0] = (color >> 24);
        	game->img.addr[pixel + 1] = (color >> 16) & 0xFF;
        	game->img.addr[pixel + 2] = (color >> 8) & 0xFF;
        	game->img.addr[pixel + 3] = (color) & 0xFF;
    	}
		else if (game->img.endian == 0)
		{
			game->img.addr[pixel + 0] = (color) & 0xFF;
			game->img.addr[pixel + 1] = (color >> 8) & 0xFF;
			game->img.addr[pixel + 2] = (color >> 16) & 0xFF;
			game->img.addr[pixel + 3] = (color >> 24);
		}
	}
	return (game->img.img);
}


int	render2D(t_game *game)
{
	int	x;
	int	u;
	int	y;
	int	v;

	y = 0;
	v = 0;
	while (game->data->map[y])
	{
		x = 0;
		u = 0;
		while (game->data->map[y][x])
		{
			if (game->data->map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->drawing.wall, u, v);
			else
				 mlx_put_image_to_window(game->mlx, game->win, game->drawing.floor, u, v);
			u += 32;
			x++;
		}
		v += 32;
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->drawing.player \
	, game->player.x, game->player.y);
	render_rays(game);
	return (1);
}
