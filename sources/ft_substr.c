/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:23:04 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:43:49 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	sub_size;
	size_t	s_size;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	if (start > s_size)
		sub_size = 1;
	else if ((start + len) > s_size)
		sub_size = s_size - start + 1;
	else
		sub_size = len + 1;
	new_str = malloc(sub_size);
	if (new_str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < s_size && j < len)
		new_str[j++] = ((char *)s)[i++];
	new_str[j] = '\0';
	return (new_str);
}
