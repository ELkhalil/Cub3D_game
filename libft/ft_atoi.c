/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:03:05 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:40:34 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sign_check(int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	tmp;
	long	result;
	int		i;
	int		sign;

	tmp = 0;
	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if (tmp > result)
			return (sign_check(sign));
		tmp = result;
		i++;
	}
	return (result * sign);
}
