/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:38:55 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/16 15:28:35 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_init_pos(t_game *game, int x, int y)
{
	if (game->data->map[x][y] == 'N')
		game->player.pos = NORTH;
	else if (game->data->map[x][y] == 'S')
		game->player.pos = SOUTH;
	else if (game->data->map[x][y] == 'E')
		game->player.pos = EAST;
	else if (game->data->map[x][y] == 'W')
		game->player.pos = WEST;
}

void	init_player(t_game *game)
{
	game->player.x = game->data->p_x * 32;
	game->player.y = game->data->p_y * 32;
	set_init_pos(game, game->data->p_y, game->data->p_x);
	game->player.move_speed = 8;
	game->player.rotation_speed = 8.0;
	if (game->player.pos == NORTH)
		game->player.rotation_angle = 1.5 * PI;
	else if (game->player.pos == SOUTH)
		game->player.rotation_angle = 0.5 * PI;
	else if (game->player.pos == WEST)
		game->player.rotation_angle = PI;
	else if (game->player.pos == EAST)
		game->player.rotation_angle = 0;
	game->player.fov = 60 * (PI / 180);
	game->player.rays = malloc(sizeof(t_ray) * game->win_width);
	if (!game->player.rays)
		exit(1);
}

void	_init_game(t_game *game)
{
	game->win_width = ft_strlen(game->data->map[0]) * 32;
	game->win_height = game->data->map_height * 32;
	init_player(game);
	game->map.ground.red = game->data->f[0];
	game->map.ground.green = game->data->f[1];
	game->map.ground.blue = game->data->f[2];
	game->map.sky.red = game->data->c[0];
	game->map.sky.green = game->data->c[1];
	game->map.sky.blue = game->data->c[2];
}
