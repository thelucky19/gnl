/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:49:36 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:35:10 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	line 24: 2nd typecast not needed
*/
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
		*((unsigned char *)str + count++) = (unsigned char) c;
	return (str);
}
