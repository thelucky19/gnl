/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-f <jlucas-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:53:35 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/05/23 19:31:03 by jlucas-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t elem_size)
{
	void	*dest;

	dest = malloc(n_elem * elem_size);
	if (dest == NULL)
		return (0);
	ft_memset(dest, 0, n_elem * elem_size);
	return (dest);
}
