/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_colors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:02:43 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/19 16:31:36 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_valid_num(char *num)
{
	int	i;
	int	nbr;

	i = 0;
	if (!num)
		return (0);
	nbr = ft_atoi(num);
	if (nbr < 0 || nbr > 255)
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	extract_colors(t_data **data, char *line, int flag, int i)
{
	char	*tmp;
	char	**splited;

	if (count_char(line, ',') != 2)
		return (ft_error("Try with correct RGB Colors!"), exit(1), 1);
	splited = ft_split(ft_strchr(line, ' '), ',');
	if (!splited)
		return (ft_error("Split Failure\n"), exit(1), 1);
	while (splited[++i])
	{
		tmp = ft_strtrim(splited[i], " ");
		if (is_valid_num(tmp))
		{
			if (flag)
				(*data)->f[i] = ft_atoi(splited[i]);
			else
				(*data)->c[i] = ft_atoi(splited[i]);
		}
		else
			return (ft_error("Try with Valid RGB Colors!"), exit(1), 1);
		free(tmp);
	}
	if (i != 3)
		return (ft_error("Try with Valid Number of RGB Colors!"), exit(1), 1);
	return (free_array(splited), EXIT_SUCCESS);
}
