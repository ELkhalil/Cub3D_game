/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:09:49 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/17 20:40:49 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_data(t_data **data)
{
	(*data)->no = NULL;
	(*data)->so = NULL;
	(*data)->we = NULL;
	(*data)->ea = NULL;
	(*data)->f[0] = -1;
	(*data)->c[0] = -1;
	(*data)->map = NULL;
}

void	fill_data(t_data **data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		line = get_next_line(fd);
	}
	free(line);
	if (data)
		printf("\ntest\n");
}

t_data	*parse_game_data(char *map_path)
{
	int		fd;
	t_data  *data;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Error Opening Map"), NULL);
	data = malloc(sizeof(t_data));
	if(!data)
		return (NULL);
	init_data(&data);
	fill_data(&data, fd);
	return (data);
}
