/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-f <jlucas-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:31:32 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/05/21 13:31:32 by jlucas-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*runsrc;
	size_t		count;

	if (size <= ft_strlen(dest) || src == NULL || dest == NULL)
		return (size + ft_strlen(src));
	count = 0;
	while (*(dest + count) != '\0')
		++count;
	runsrc = (char *)src;
	while (*runsrc != '\0' && count < size - 1)
	{
		*(dest + count) = *runsrc;
		++runsrc;
		++count;
	}
	*(dest + count) = '\0';
	return (ft_strlen(dest) + ft_strlen(runsrc));
}
