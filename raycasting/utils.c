/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:05 by mmounaji          #+#    #+#             */
/*   Updated: 2023/04/29 20:58:03 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	_out_range(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (y < 0 || y >= i || x < 0 || x >= (int)ft_strlen(map[y]));
}
