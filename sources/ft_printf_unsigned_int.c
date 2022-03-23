/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:43:05 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/09/01 11:42:09 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_unsigned_int(unsigned int u)
{
	int	printed;

	printed = 0;
	if (u > 9)
		printed += ft_printf_unsigned_int(u / 10);
	return (printed += ft_printf_char('0' + (u % 10)));
}
