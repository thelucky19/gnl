/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:16:09 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:35:37 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 **	last 2 lines shouldnt have prob: aux/10, aux%10 are within int/char range
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	aux;

	aux = n;
	if (aux < 0)
	{
		write(fd, "-", 1);
		aux *= -1;
	}
	if (aux > 9)
		ft_putnbr_fd((int)(aux / 10), fd);
	ft_putchar_fd('0' + (char)(aux % 10), fd);
}
