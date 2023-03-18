/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:26:51 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:26:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* check if surrounded by walls */
int	check_surrounds(t_data *map, int i, int j)
{
	if (map->map[i][j] == '0' && (map->map[i][j - 1] == ' '
		|| map->map[i][j + 1] == ' ' || map->map[i - 1][j] == ' '
			|| map->map[i + 1][j] == ' '))
		return (ft_error("Map is not surrounded by walls\n"), exit(1), 1);
	if (map->map[i][j] == '0' && (map->map[i][j - 1] == '\0'
		|| map->map[i][j + 1] == '\0' || map->map[i - 1][j] == '\0'
			|| map->map[i + 1][j] == '\0'))
		return (ft_error("Map is not surrounded by walls\n"), exit(1), 1);
	return (EXIT_SUCCESS);
}

/* find player position and count invalid players */
int	find_and_count_players(t_data *map)
{
	int		count;
	int		i;
	int		j;
	char	c;

	i = -1;
	count = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			check_surrounds(map, i, j);
			c = map->map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				count ++;
				map->p_x = j;
				map->p_y = i;
			}
		}
	}
	if (count != 1)
		return (ft_error("Only one Player is allowed\n"), exit(1), 1);
	return (EXIT_SUCCESS);
}

/* check for composed characters (0, 1, N, S, E, W) */
int	is_content_valid(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0'
			|| map[i] == 'N' || map[i] == 'S'
			|| map[i] == 'E' || map[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

/* check if it is a wall */
int	is_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/* check if all previous data is filled */
int	is_filled(t_data *data)
{
	if (!data)
		return (0);
	if (*data->no && *data->so && *data->we && *data->ea
		&& data->f[0] != -1 && data->c[0] != -1)
		return (1);
	return (0);
}
