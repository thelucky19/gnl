/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:03:24 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:25:49 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_quant(int n)
{
	int			quant;
	long int	aux;

	aux = n;
	quant = 1;
	if (aux < 0)
	{
		++quant;
		aux *= -1;
	}
	while (aux > 9)
	{
		aux /= 10;
		++quant;
	}
	return (quant);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			dig_quant;
	int			i;
	long int	aux;

	dig_quant = digit_quant(n);
	str = malloc((size_t) dig_quant + 1);
	if (str == NULL)
		return (NULL);
	str[dig_quant--] = '\0';
	i = dig_quant;
	aux = n;
	if (n < 0)
	{
		str[0] = '-';
		aux *= (-1);
		--dig_quant;
	}
	while (dig_quant >= 0)
	{
		str[i--] = '0' + (char)(aux % 10);
		aux /= 10;
		--dig_quant;
	}
	return (str);
}
