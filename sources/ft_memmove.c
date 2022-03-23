/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:50:39 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:30:46 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			*((unsigned char *)dest + i - 1) = *((unsigned char *)src + i - 1);
			--i;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
