/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:06:26 by aelkhali          #+#    #+#             */
/*   Updated: 2023/05/02 20:41:16 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./srcs/parsing/parser.h"
# include "./srcs/raycasting/raycasting.h"

/* parsing */
t_data	*parse_game_data(char *map_path);
#endif