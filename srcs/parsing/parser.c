/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:09:49 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/19 14:33:44 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	fill_data(t_data **data, char *line, int fd, char *path)
{
	while (line)
	{
		if (!ft_strncmp(line, "NO ", 3))
			(*data)->no = ft_strtrim(ft_strchr(line, ' '), " ");
		else if (!ft_strncmp(line, "SO ", 3))
			(*data)->so = ft_strtrim(ft_strchr(line, ' '), " ");
		else if (!ft_strncmp(line, "WE ", 3))
			(*data)->we = ft_strtrim(ft_strchr(line, ' '), " ");
		else if (!ft_strncmp(line, "EA ", 3))
			(*data)->ea = ft_strtrim(ft_strchr(line, ' '), " ");
		else if (!ft_strncmp(line, "F ", 2))
			extract_colors(data, line, 1);
		else if (!ft_strncmp(line, "C ", 2))
			extract_colors(data, line, 0);
		else if (*(line + skip_spcs(line)) == '1' && is_filled(*data))
			line = extract_map_content(data, line, fd, path);
		else if (!*(line + skip_spcs(line)))
			;
		else
			return (ft_error("Invalid map content\n"), exit(1), 1);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

t_data	*parse_game_data(char *map_path)
{
	int		fd;
	t_data	*data;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Error Opening The File"), exit(1), NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	line = get_next_line(fd);
	init_data(&data);
	fill_data(&data, line, fd, map_path);
	return (data);
}
