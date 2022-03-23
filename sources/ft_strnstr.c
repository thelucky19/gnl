/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:26:41 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:51:51 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char	*haystack;
	char	*needle;
	char	*needle_in_haystack;
	size_t	i_hays;
	size_t	i_need;

	haystack = (char *)str;
	if (*to_find == '\0')
		return (haystack);
	i_hays = 0;
	while (i_hays < n && *(haystack + i_hays) != '\0')
	{
		i_need = 0;
		needle = (char *)to_find;
		needle_in_haystack = (haystack + i_hays);
		while (*(needle_in_haystack + i_need) == *(needle + i_need)
			&& *(needle + i_need) != '\0' && i_hays + i_need < n)
			++i_need;
		if (*(needle + i_need) == '\0')
			return (haystack + i_hays);
		++i_hays;
	}
	return (NULL);
}
