/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:36:40 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/15 12:38:32 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	close_game()
{
	write(1, "Good Bye !\n", 12);
	exit(0);
}

int raycaster(t_game *game)
{
	_init_game(game);
    game->mlx = mlx_init();
    if (!game->mlx)
        return (ft_error("MLX INIT FAILED\n"), exit(1), 1);
    game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Cub3D");
    if (!game->mlx)
        return (ft_error("WINDOW INIT FAILED\n"), exit(1), 1);
	game->drawing.player = draw_image(game, RED_PIXEL, 8, 8);
	game->drawing.wall = draw_image(game, GREY, 32, 32);
	game->drawing.floor = draw_image(game, WHITE_PIXEL, 32, 32);
    mlx_hook(game->win, 2, 0, key_hook_hundler, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	render2D(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}