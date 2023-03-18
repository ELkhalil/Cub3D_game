/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:24:37 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:25:44 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* Calculate map size for allocation */
int	map_size(char *line, int fd)
{
	int		x;
	char	c;

	x = 0;
	if (!line)
		return (EXIT_FAILURE);
	if (!is_wall(line))
		return (ft_error("Map must be surrounded by walls\n"), exit(1), 1);
	while (line)
	{
		x++;
		c = *(line + skip_spcs(line));
		if (!*line || (c != '1' && c != '\0' && !is_content_valid(line)))
			return (ft_error("Try map with (0, 1, N, S, E, W)\n"), exit(1), 1);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	line = NULL;
	return (x);
}

/* Cpy Map from file to **map */
int	cpy_map_content(t_data **data, char *line, int fd2)
{
	int	i;

	i = 0;
	while (line)
	{
		(*data)->map[i] = line;
		line = get_next_line(fd2);
		i++;
	}
	(*data)->map[i] = NULL;
	close(fd2);
	find_and_count_players(*data);
	return (EXIT_SUCCESS);
}
