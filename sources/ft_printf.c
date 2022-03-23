/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:40:28 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/09/01 10:59:26 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	conversion(char c, va_list params)
{
	t_bool	is_valid_conversion;

	is_valid_conversion = c == 'c' || c == 'i' || c == 'd' || c == 'p'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X' || c == '%';
	if (!is_valid_conversion)
		return (-1);
	if (c == 'c')
		return (ft_printf_char(va_arg(params, int)));
	if (c == 'i' || c == 'd')
		return (ft_printf_int(va_arg(params, int)));
	if (c == 'p')
		return (ft_printf_ptr(va_arg(params, void *)));
	if (c == 's')
		return (ft_printf_str(va_arg(params, char *)));
	if (c == 'u')
		return (ft_printf_unsigned_int(va_arg(params, unsigned int)));
	if (c == 'x')
		return (ft_printf_hexadec_unsigned_int(va_arg(params, int)));
	if (c == 'X')
		return (ft_printf_hexadec_uppercase_unsigned_int(va_arg(params, int)));
	return (write(1, &c, 1));
}

static int	set_conversion(va_list params, char c, int *printed)
{
	va_list	params_copy;
	int		printed_delta;

	va_copy(params_copy, params);
	printed_delta = conversion(c, params_copy);
	*printed += printed_delta;
	va_end(params_copy);
	return (printed_delta);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	params;
	size_t	i;
	int		printed;

	va_start(params, format_str);
	i = 0;
	printed = 0;
	while (format_str[i] != 0 && printed != -1)
	{
		if (format_str[i] != '%')
		{
			ft_putchar_fd(format_str[i++], 1);
			++printed;
		}
		else
		{
			if (set_conversion(params, format_str[i + 1], &printed) == -1)
				printed = -1;
			else if (format_str[i + 1] != '%')
				va_arg(params, int);
			i += 2;
		}
	}
	va_end(params);
	return (printed);
}
