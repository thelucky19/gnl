/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:28:36 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/13 22:17:26 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *orig)
{
	char	*dup;
	size_t	mem_size;

	mem_size = ft_strlen(orig) + 1;
	dup = malloc(mem_size);
	if (dup == NULL)
		return (NULL);
	dup = ft_memcpy(dup, orig, mem_size);
	return (dup);
}
