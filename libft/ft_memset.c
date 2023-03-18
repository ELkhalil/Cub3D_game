/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:34:18 by aelkhali          #+#    #+#             */
/*   Updated: 2022/10/25 10:49:18 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cas_b;
	unsigned char	cas_c;
	size_t			i;

	i = 0;
	cas_b = (unsigned char *)b;
	cas_c = (unsigned char)c;
	while (i < len)
	{
		cas_b[i] = cas_c;
		i++;
	}
	return (b);
}
