/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:45:23 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:39:07 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*start1;
	unsigned char	*start2;

	count = 0;
	start1 = (unsigned char *)s1;
	start2 = (unsigned char *)s2;
	while (*start2 != '\0' && count < n)
	{
		if (*start2 != *start1)
			return (*start1 - *start2);
		++start1;
		++start2;
		++count;
	}
	if (count < n)
		return (*start1 - *start2);
	return (0);
}
