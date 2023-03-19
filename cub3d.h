/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:06:26 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/19 20:06:10 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./srcs/parsing/parser.h"


/* Game Play infos*/
typedef struct sol_game
{
	t_data	*data;
	void	*mlx;
	void	*win;
	int		t_size;
}			t_game;

/* Raycasting */
int raycaster(t_game *game);

/* parsing */
t_data	*parse_game_data(char *map_path);

#endif