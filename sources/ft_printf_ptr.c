/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:42:47 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/09/01 10:23:40 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	euclidian_remainder(long unsigned int dividend, int divisor)
{
	long unsigned int	quotient;

	quotient = dividend / divisor;
	return (dividend - quotient * divisor);
}

static int	ft_printf_hexad_long_unsig_int(long unsigned int lx)
{
	int	printed;
	int	remainder;

	printed = 0;
	if (lx > 15)
		printed += ft_printf_hexad_long_unsig_int(lx / 16);
	remainder = euclidian_remainder(lx, 16);
	if (remainder < 10)
		return (printed += ft_printf_char('0' + remainder));
	return (printed += ft_printf_char('a' + remainder - 10));
}

int	ft_printf_ptr(void *ptr)
{
	int					printed;
	long unsigned int	ptr_as_long_unsigned;

	printed = 0;
	printed += (ft_printf_char('0'));
	printed += (ft_printf_char('x'));
	ptr_as_long_unsigned = (long unsigned int) ptr;
	printed += ft_printf_hexad_long_unsig_int(ptr_as_long_unsigned);
	return (printed);
}
