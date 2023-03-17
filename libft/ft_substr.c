/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:59:05 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/17 17:20:43 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*sub_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_str = malloc (len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
