/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounaji <mmounaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:06:10 by aelkhali          #+#    #+#             */
/*   Updated: 2023/04/08 14:24:59 by mmounaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	if(!s1)
		return(1);
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] && c_s2[i] && c_s1[i] == c_s2[i] && i < n)
		i++;
	if ((c_s1[i] == '\0' && c_s2[i] == '\0') || i == n)
		return (0);
	return (c_s1[i] - c_s2[i]);
}
