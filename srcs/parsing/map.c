/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:45 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:25:03 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*extract_map_content(t_data **data, char *line, int fd, char *path)
{
	char	*buff;
	int		fd2;

	(*data)->map = malloc (sizeof(char *) * (map_size(line, fd) + 1));
	if (!(*data)->map)
		return (ft_error("Map Allocation Failed\n"), exit(1), NULL);
	fd2 = open(path, O_RDONLY);
	if (fd2 < 0)
		return (ft_error("Error Opening The File"), exit(1), NULL);
	buff = get_next_line(fd2);
	while (buff)
	{
		if (*(buff + skip_spcs(buff)) == '1')
			cpy_map_content(data, buff, fd2);
		if (buff)
			free(buff);
		buff = get_next_line(fd2);
	}
	return (NULL);
}
