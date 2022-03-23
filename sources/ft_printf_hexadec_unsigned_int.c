/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadec_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:43:19 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/09/01 10:23:37 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	euclidian_remainder(unsigned int dividend, unsigned int divisor)
{
	unsigned int	quotient;

	quotient = dividend / divisor;
	return (dividend - quotient * divisor);
}

int	ft_printf_hexadec_unsigned_int(unsigned int x)
{
	int				printed;
	unsigned int	remainder;

	printed = 0;
	if (x > 15)
		printed += ft_printf_hexadec_unsigned_int(x / 16);
	remainder = euclidian_remainder(x, 16);
	if (remainder < 10)
		return (printed += ft_printf_char('0' + remainder));
	return (printed += ft_printf_char('a' + remainder - 10));
}
