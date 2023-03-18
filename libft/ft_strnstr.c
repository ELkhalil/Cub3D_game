/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:25:06 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 17:40:34 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (needle[0] == '\0' || (haystack == needle))
		return ((char *)haystack);
	if (len > 0)
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				while (haystack[i + j] == needle[j] && (i + j) < len)
					j++;
				if (!needle[j])
					return ((char *)&haystack[i]);
			}
			i++;
		}
	}
	return (NULL);
}
