/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:40:24 by aelkhali          #+#    #+#             */
/*   Updated: 2022/10/25 11:44:54 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;

	if (count && (SIZE_MAX / count) < size)
		return (NULL);
	allocated = malloc (count * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, count * size);
	return (allocated);
}
