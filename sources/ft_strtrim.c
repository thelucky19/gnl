/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:49:42 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/11 20:06:58 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char *)s1;
	while (*str && ft_strchr(set, *str))
		++str;
	i = ft_strlen(str);
	while (i && ft_strchr(set, str[i]))
		--i;
	return (ft_substr(str, 0, i + 1));
}
