/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:47:05 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/15 13:28:00 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
#define RAYCASTING_H

# define PI 3.14
# define GREEN_PIXEL 0xFF00
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0x000000
# define GREY 0x808080
# include "../cub3d.h"

/* -------- KEY VALUES -------- */
# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define WALL '1'
# define EMPTY '0'
# define EXIT 'E'
# define PLAYER 'P'
# define FLOOR "F"
# define CEILLING "C"
# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

/* -------- COLORS -------- */
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef enum s_position
{
	SOUTH = 83,
	EAST = 78,
	WEST = 87,
	NORTH = 69,
}				t_position;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_ray
{
	double		angle;
	t_vector	wall_hit;
	double		distance;
	int			wall_height;
}				t_ray;

typedef struct s_player
{
	int				x;
	double			fov;
	int				y;
	enum s_position	pos;
	double			rotation_angle;
	double			move_speed;
	double			rotation_speed;
}	t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_map
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_rgb	ground;
	t_rgb	sky;
}	t_map;


typedef struct s_2d
{
	void	*wall;
	void	*floor;
	void	*player;
}	t_2d;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_map		map;
	t_img		img;
	t_img		raycast;
	t_2d		drawing;
	t_player	player;
	t_data		*data;
}	t_game;

int		raycaster(t_game *game);
void	_init_game(t_game *game);
int		render2D(t_game *game);
int		key_hook_hundler(int key_id, t_game *game);
void	*draw_image(t_game *game, int color, int w, int h);
void	render_rays(t_game *game);
int 	draw_line(t_game *game, int beginX, int beginY, int endX, int endY, int color);
#endif