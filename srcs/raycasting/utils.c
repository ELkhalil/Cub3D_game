/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:05 by mmounaji          #+#    #+#             */
/*   Updated: 2023/05/02 20:59:10 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	_out_range(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (x < 0 || x >= (int)ft_strlen(map[y]) || y < 0 || y >= i);
}
