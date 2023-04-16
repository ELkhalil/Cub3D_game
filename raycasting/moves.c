/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:57:57 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/16 15:41:22 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	out_range(t_game *game, double x, double y)
{
	int	x1;
	int	y1;
	int	i;

	i = 0;
	while (game->data->map[i])
		i++;
	x1 = (int)floor(x / 32);
	y1 = (int)floor(y / 32);
	return (y1 < 0 || y1 >= i || x1 < 0 || x1 >= \
	(int)ft_strlen(game->data->map[y1]));
}

int	check_wall(t_game *game, double x, double y)
{
	int	x1;
	int	y1;

	x1 = (int)floor(x / 32);
	y1 = (int)floor(y / 32);
	if (game->data->map[x1][y1] == WALL)
		return (1);
	return (0);
}

void	update_rotation(t_game *game, int key_id)
{
	if (key_id == RIGHT_R)
		game->player.rotation_angle -= game->player.rotation_speed \
		/ 300 * PI * 2;
	else if (key_id == LEFT_R)
		game->player.rotation_angle += game->player.rotation_speed \
		/ 300 * PI * 2;
}


void	move_player(t_game *game, double p_angle, int flag)
{
	double	x;
	double	y;

	x = game->player.x + (cos(p_angle) \
	* game->player.move_speed * flag);
	y = game->player.y + (sin(p_angle) \
	* game->player.move_speed * flag);
	if (check_wall(game, y, x) == 0)
	{
		game->player.x = x;
		game->player.y = y;
	}
}

int	key_hook_hundler(int key_id, t_game *game)
{
	if (key_id == 53)
	{
		write(1, "Good Bye !\n", 12);
		exit(0);
	}
	else if (key_id == UP_M)
		move_player(game, game->player.rotation_angle, 1);
	else if (key_id == DOWN_M)
		move_player(game, game->player.rotation_angle, -1);
	else if (key_id == LEFT_M)
		move_player(game, game->player.rotation_angle + 0.5 * PI, -1);
	else if (key_id == RIGHT_M)
		move_player(game, game->player.rotation_angle + 0.5 * PI, 1);
	update_rotation(game, key_id);
	if (key_id == RIGHT_M || key_id == LEFT_M || key_id == UP_M \
	|| key_id == DOWN_M || key_id == RIGHT_R || key_id == LEFT_R)
	{
		mlx_clear_window(game->mlx, game->win);
		render2D(game);
	}
	return (1);
}
