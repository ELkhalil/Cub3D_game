
#include "raycasting.h"

int _key_press(int key, t_game *leet3d)
{
	if (key == 53 || key == 12)
		close_game();
	if (key == RIGHT_R)
		_rotate_player(leet3d, -(leet3d->rotation_angle));
	if (key == LEFT_R)
		_rotate_player(leet3d, leet3d->rotation_angle);
	if (key == UP_M)
		_move_forward(leet3d);
	if (key == DOWN_M)
		_move_back(leet3d);
	if (key == RIGHT_M)
		_move_right(leet3d);
	if (key == LEFT_M)
		_move_left(leet3d);
	else
		return (1);
	return (0);
}
