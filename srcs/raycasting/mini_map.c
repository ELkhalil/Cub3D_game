/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:26:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/05/01 19:51:17 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	render_tile(t_game *game, t_img *img, t_tile tile)
{
	int	pixel_row;
	int	pixel_col;
	int	pixel_x;
	int	pixel_y;
	int	color;

	if (tile.is_player)
		color = GREEN;
	else
		color = get_color(game, tile.map_row, tile.map_col);
	pixel_row = 0;
	pixel_y = tile.tile_row * MINI_TILE;
	pixel_x = tile.tile_col * MINI_TILE;
	while (pixel_row < MINI_TILE)
	{
		pixel_col = 0;
		while (pixel_col < MINI_TILE)
		{
			set_pixel(img, pixel_x + pixel_col, pixel_y + pixel_row, color);
			pixel_col++;
		}
		pixel_row++;
	}
}

void	handle_drawings(t_game *game, t_img *img)
{
	int	tile_x;
	int	tile_y;
	int	start_x;
	int	start_y;

	start_x = ((int)game->pos.x) - MINI_MAP_H / MINI_TILE / 2;
	tile_y = -1;
	while (++tile_y < MINI_MAP_H / MINI_TILE)
	{
		tile_x = -1;
		start_y = ((int)game->pos.y) - MINI_MAP_W / MINI_TILE / 2;
		while (++tile_x < MINI_MAP_W / MINI_TILE)
		{
			if (start_x >= 0 && start_y >= 0)
				render_tile(game, img, (t_tile){tile_y, tile_x, \
				start_x, start_y, 0});
			else
				render_tile(game, img, (t_tile){tile_y, tile_x, 0, 0, 0});
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
	render_tile(game, &map_img, (t_tile){MINI_MAP_H / 2 / MINI_TILE, \
	MINI_MAP_W / 2 / MINI_TILE, 0, 0, 1});
	mlx_put_image_to_window(game->mlx, game->win_ptr, \
	map_img.img, 0, 0);
	mlx_destroy_image(game->mlx, map_img.img);
}
