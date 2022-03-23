/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:50:37 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:37:41 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (src == NULL || dest == NULL)
		return (0);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && ((char *)src)[i] != 0)
		{
			*(dest + i) = ((char *)src)[i];
			++i;
		}
		*(dest + i) = '\0';
	}
	return (ft_strlen(src));
}
