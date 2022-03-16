/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:13:49 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/08/23 12:13:54 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (((char *)str)[len] != '\0')
		++len;
	return (len);
}

char	*ft_strnchr(const char *s, int c, size_t range)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (*str != '\0' && i < range)
	{
		if (*str == (char) c)
			return (str);
		++str;
		++i;
	}
	if (*str == (char) c)
		return (str);
	return (NULL);
}

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

ssize_t	line_ended(char *buf, int delta)
{
	size_t	end_i;

	if (ft_strnchr(buf, '\n', delta) == NULL)
		return (0);
	end_i = 0;
	while (buf[end_i] != '\n')
		++end_i;
	return (end_i + 1);
}
