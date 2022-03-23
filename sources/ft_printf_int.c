/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:42:29 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/09/01 11:33:21 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_int(int i)
{
	int			printed;
	long int	aux;

	ft_putnbr_fd(i, 1);
	printed = 1;
	aux = i;
	if (aux < 0)
	{
		++printed;
		aux *= -1;
	}
	while (aux / 10 > 0)
	{
		++printed;
		aux /= 10;
	}
	return (printed);
}
