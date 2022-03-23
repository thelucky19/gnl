/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:32:54 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:28:29 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*start1;
	unsigned char	*start2;

	count = 0;
	start1 = (unsigned char *)s1;
	start2 = (unsigned char *)s2;
	while (count < n)
	{
		if (*start2 != *start1)
			return (*start1 - *start2);
		++start1;
		++start2;
		++count;
	}
	return (0);
}
