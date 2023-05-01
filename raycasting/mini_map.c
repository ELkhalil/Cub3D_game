/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:26:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/05/01 18:11:56 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_pixel(t_img *img, int x, int y, int color)
{
	*(int *)(img->addr + (y * img->line_length / 4) + x) = color;
}

int	get_color(t_game *game, int x, int y)
{
	int	color;

	color = GREY;
	if (x >= game->data->map_height || y >= game->data->map_width)
		color = GREY;
	else if (game->data->map[x][y] == '1')
		color = BLACK_PIXEL;
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

void draw_player(t_game *game, t_img *img, int row, int col, int flag)
{
    int x_offset;
    int y_offset;
    int x;
    int y;

    x_offset = -1;
    while (++x_offset < MINI_TILE)
    {
        y_offset = -1;
        while (++y_offset < MINI_TILE)
        {
            x = col * MINI_TILE + y_offset;
            y = row * MINI_TILE + x_offset;
            if (flag)
            {
                if (!wach_wall(game, x, y))
                    set_pixel(img, x, y, GREEN);
                else
                    set_pixel(img, x, y, GREY);
            }
            else
                set_pixel(img, x, y, GREY);
        }
    }
}

void draw_rect(t_game *game, t_img *img, int tile_row, int tile_col, int map_row, int map_col)
{
    int pixel_row;
    int pixel_col;
    int pixel_x;
    int pixel_y;

    pixel_row = 0;
    while (pixel_row < MINI_TILE)
    {
        pixel_col = 0;
        while (pixel_col < MINI_TILE)
        {
            pixel_x = tile_col * MINI_TILE;
            pixel_y = tile_row * MINI_TILE;
            set_pixel(img, pixel_x + pixel_col, pixel_y + pixel_row, \
			get_color(game, map_row, map_col));
            pixel_col++;
        }
        pixel_row++;
    }
}

void	handle_drawings(t_game *game, t_img *img)
{
	int		tile_x;
	int		tile_y;
	int		start_x;
	int		start_y;

	start_x = ((int)game->pos.x) - MINI_MAP_H / MINI_TILE / 2;
	tile_y = -1;
	while (++tile_y < MINI_MAP_H / MINI_TILE)
	{
		tile_x = -1;
		start_y = ((int)game->pos.y) - MINI_MAP_W / MINI_TILE / 2;
		while (++tile_x < MINI_MAP_W / MINI_TILE)
		{
			if (start_x >= 0 && start_y >= 0)
				draw_rect(game, img, tile_y, tile_x, start_x, start_y);
			else
				draw_player(game, img, tile_y, tile_x, 0);
			start_y++;
		}
		start_x++;
	}
}

void	_init_minimap(t_game *game)
{
	t_img	map_img;

	map_img.img = mlx_new_image(game->mlx, MINI_MAP_W, MINI_MAP_H);
	map_img.addr = (int *)mlx_get_data_addr(map_img.img, \
	&map_img.bits_per_pixel, &map_img.line_length, &map_img.endian);
	handle_drawings(game, &map_img);
	draw_player(game, &map_img, MINI_MAP_H / 2 / MINI_TILE, \
	MINI_MAP_W / 2 / MINI_TILE, 1);
	mlx_put_image_to_window(game->mlx, game->win_ptr, \
	map_img.img, 0, 0);
	mlx_destroy_image(game->mlx, map_img.img);
}
