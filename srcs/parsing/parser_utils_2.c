/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:38:55 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:52:01 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_filled(t_data *data)
{
	if (!data)
		return (0);
	if (*data->no && *data->so && *data->we && *data->ea
		&& data->f[0] != -1 && data->c[0] != -1)
		return (1);
	return (0);
}

int	extract_colors(t_data **data, char *line, int flag)
{
	int		i;
	char	*tmp;
	char	**splited;

	if (!line || !data)
		return (EXIT_FAILURE);
	i = -1;
	tmp = ft_strtrim(ft_strchr(line, ' '), " \t\n");
	splited = ft_split(tmp, ',');
	if (!splited || !tmp || count_sc(splited) < 3)
		return (ft_error("Try with correct RGB Colors!"), exit(1), 1);
	while (splited[++i])
	{
		if (is_valid_num(splited[i]))
		{
			if (flag)
				(*data)->f[i] = ft_atoi(splited[i]);
			else
				(*data)->c[i] = ft_atoi(splited[i]);
		}
		else
			return (ft_error("Try with Valid RGB Colors!"), exit(1), 1);
	}
	return (free_array(splited), free(tmp), EXIT_SUCCESS);
}
