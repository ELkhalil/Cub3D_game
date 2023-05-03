/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:47:05 by mmounaji          #+#    #+#             */
/*   Updated: 2023/05/03 12:38:46 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define PI 3.14\

/* Mini_Map Settings*/
# define MINI_MAP_H 200
# define MINI_MAP_W 200
# define MINI_TILE 10

# include "../../cub3d.h"

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
# define PLAYER 'P'
# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

/* -------- COLORS -------- */
# define GREEN_PIXEL 0xFF00
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED_PIXEL 0xFF0000
# define TRANSPARENT 0xFFFFFF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x00000010
# define GREY 0x80808080
# define GREY_HH 0x20202020

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_img
{
	int			width;
	int			height;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct tile
{
	int		tile_row;
	int		tile_col;
	int		map_row;
	int		map_col;
	int		is_player;
}	t_tile;

typedef struct s_game
{
	void		*mlx;
	void		*win_ptr;
	t_data		*data;
	t_img		img;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		camera_x;
	t_vector	raydir;
	t_vector	delta_dist;
	t_vector	side_dist;
	double		perp_wall_dist;
	double		move_speed;
	double		rotation_angle;
	double		wallx;
	double		tex_pos;
	double		tex_step;
	int			color;
	t_vector	step;
	int			_texturex;
	int			_texturey;
	int			hit;
	int			side;
	t_vector	map;
	void		*n;
	void		*s;
	void		*e;
	void		*w;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			i;
	t_img		texture;
	int			window_w;
	int			window_h;
}				t_game;

int		_raycaster(t_game *game);
int		_cub3d(void *game);
void	_move_back(t_game *leet3d);
void	_rotate_player(t_game *leet3d, double angle);
void	_move_right(t_game *leet3d);
void	_move_left(t_game *leet3d);
void	_move_forward(t_game *leet3d);
int		_key_press(int key, t_game *leet3d);
void	_default_draw_init(t_game	*leet3d);
void	_load_textures(t_game *leet3d);
void	_leet3d_init1(t_game *leet3d);
void	_leet3d_init1(t_game *leet3d);
int		close_game(void);
void	_drawing_textures(t_game *leet3d);
int		_out_range(char **map, int x, int y);
void	rebuild_image(t_game *leet3d);
void	_setup_textures(t_game *leet3d);
void	_drawing_floor(t_game *leet3d);
void	_drawing_ceiling(t_game *leet3d);
int		_mouse_events(int key, int x, int y, t_game *leet3d);
int		get_rgb_color(int red, int green, int blue);

/* MiniMap_Utils */
void	_init_minimap(t_game *game);
void	set_pixel(t_img *img, int x, int y, int color);
int		get_color(t_game *game, int x, int y);
int		wach_wall(t_game *game, int x, int y);

#endif