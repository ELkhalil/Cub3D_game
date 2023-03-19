/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:59:43 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/19 20:18:17 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

#define GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0x2389da

int	key_hook_hundler(int key_id)
{
	if (key_id == 53)
	{
		write(1, "Good Bye !\n", 12);
		exit(0);
	}
	if (key_id == 13 || key_id == 1 || key_id == 2 || key_id == 0)
		printf("Keys Pressed\n");
	return (1);
}

int	close_game()
{
	write(1, "Good Bye !\n", 12);
	exit(0);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}


typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int render_rect(t_game *game, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(game->mlx, game->win, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
			mlx_pixel_put(game->mlx, game->win, j++, i, color);
		++i;
	}
}

int	render(t_game *game)
{
    render_background(game, WHITE_PIXEL);
	render_rect(game, (t_rect){1920 - 100, 1080 - 100,
			100, 100, GREEN_PIXEL});
	render_rect(game, (t_rect){0, 0, 100, 100, RED_PIXEL});
	return (0);
}

int raycaster(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (ft_error("MLX INIT FAILED\n"), exit(1), 1);
    game->win = mlx_new_window(game->mlx, 1920, 1080, "Cub3D");
    if (!game->mlx)
        return (ft_error("WINDOW INIT FAILED\n"), exit(1), 1);
    mlx_hook(game->win, 2, 0, key_hook_hundler, game);
	mlx_hook(game->win, 17, 0, close_game, game);
    mlx_loop_hook(game->mlx, render, game);
    
    mlx_loop(game->mlx);
    return (EXIT_SUCCESS);
}