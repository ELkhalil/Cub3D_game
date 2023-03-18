/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:55 by aelkhali          #+#    #+#             */
/*   Updated: 2022/10/19 12:05:54 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_calculator(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		len;
	long	num;

	num = n;
	len = len_calculator(num);
	num_str = malloc (len + 1);
	if (!num_str)
		return (NULL);
	num_str[len--] = '\0';
	if (num == 0)
		num_str[0] = '0';
	if (num < 0)
	{
		num_str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		num_str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (num_str);
}
