/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:02:02 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:39:35 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	c_limit;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	c_limit = dstsize - len_dst - 1;
	dst += len_dst;
	while (*src && c_limit > 0)
	{
		*dst++ = *src++;
		c_limit--;
	}
	*dst = '\0';
	return (len_dst + len_src);
}
