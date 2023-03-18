/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:34:34 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:38:19 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

void	free_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free (strs);
}

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

int	is_valid_num(char *num)
{
	int	i;
	int	nbr;

	i = 0;
	if (!num)
		return (0);
	nbr = ft_atoi(num);
	while (num[i])
	{
		if ((num[i] != ' ' && !ft_isdigit(num[i])) || (nbr < 0 && nbr > 255))
			return (0);
		i++;
	}
	return (1);
}

int	count_sc(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i ++;
	return (i);
}
