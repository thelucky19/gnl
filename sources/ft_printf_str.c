/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:42:40 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/09/01 11:22:46 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int	printed;

	if (str == NULL)
		return (write(1, "(null)", 6));
	printed = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printed);
}
