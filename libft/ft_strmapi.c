/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:06:30 by aelkhali          #+#    #+#             */
/*   Updated: 2022/10/17 10:37:56 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*created_str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	created_str = malloc(ft_strlen(s) + 1);
	if (!created_str)
		return (NULL);
	while (s[i])
	{
		created_str[i] = f(i, s[i]);
		i++;
	}
	created_str[i] = '\0';
	return (created_str);
}
