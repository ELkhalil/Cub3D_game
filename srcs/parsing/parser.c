/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:09:49 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:55:38 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	fill_data(t_data **data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO ", 3))
			(*data)->no = ft_strtrim(ft_strchr(line, ' '), " \t\n");
		else if (!ft_strncmp(line, "SO ", 3))
			(*data)->so = ft_strtrim(ft_strchr(line, ' '), " \t\n");
		else if (!ft_strncmp(line, "WE ", 3))
			(*data)->we = ft_strtrim(ft_strchr(line, ' '), " \t\n");
		else if (!ft_strncmp(line, "EA ", 3))
			(*data)->ea = ft_strtrim(ft_strchr(line, ' '), " \t\n");
		else if (!ft_strncmp(line, "F ", 2))
			extract_colors(data, line, 1);
		else if (!ft_strncmp(line, "C ", 2))
			extract_colors(data, line, 0);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (EXIT_SUCCESS);
}

t_data	*parse_game_data(char *map_path)
{
	int		fd;
	t_data	*data;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Error Opening Map"), NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_data(&data);
	fill_data(&data, fd);
	return (data);
}
