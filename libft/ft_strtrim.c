/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:41:15 by aelkhali          #+#    #+#             */
/*   Updated: 2023/03/18 10:18:46 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j]) && j)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
