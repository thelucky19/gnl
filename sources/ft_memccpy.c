/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:52:37 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:34:17 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	line 27: 2nd typecast in is needed because src is const void*
*/
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	count;

	if (n == 0)
		return (NULL);
	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
		if (*((unsigned char *)src + count) == (unsigned char)c)
			return (dest + count + 1);
		++count;
	}
	return (NULL);
}
