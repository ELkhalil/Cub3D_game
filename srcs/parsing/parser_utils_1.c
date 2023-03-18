/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:34:34 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:28:51 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* init the parsing struct */
void	init_data(t_data **data)
{
	if (!data)
		return ;
	(*data)->no = NULL;
	(*data)->so = NULL;
	(*data)->we = NULL;
	(*data)->ea = NULL;
	(*data)->f[0] = -1;
	(*data)->c[0] = -1;
	(*data)->map = NULL;
}

/* free double pointer array */
void	free_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free (strs);
}

/* count how many char in str */
int	count_char(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

/* Skip Sapces at the beginnig */
int	skip_spcs(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
