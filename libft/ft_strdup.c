/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:48:30 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/17 21:28:55 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*copied_str;
	size_t	lentgh;
	int		i;

	i = 0;
	lentgh = ft_strlen(s1);
	copied_str = malloc (lentgh + 1);
	if (!copied_str)
		return (NULL);
	while (s1[i])
	{
		copied_str[i] = s1[i];
		i++;
	}
	copied_str[i] = '\0';
	return (copied_str);
}
