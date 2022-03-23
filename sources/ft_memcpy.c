/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:51:46 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:34:05 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	line 27: 2nd typecast is needed because src is const void*
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
		++count;
	}
	return (dest);
}
