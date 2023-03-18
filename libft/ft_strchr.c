/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:25:50 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:18:12 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char	c_c;
	int		i;

	c_c = (char )c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c_c)
		i++;
	if (s[i] == '\0' && s[i] != c)
		return (NULL);
	return ((char *)&s[i]);
}
