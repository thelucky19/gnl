/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:48:00 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 15:51:17 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	char	*run;
	int		sign;
	int		num;

	run = (char *)str;
	sign = 1;
	while (*run == ' ' || *run == '\f' || *run == '\n' || *run == '\r'
		|| *run == '\t' || *run == '\v')
		++run;
	if (*run == '+' || *run == '-')
	{
		if (*run == '-')
			sign = sign * (-1);
		++run;
	}
	num = 0;
	while (*run >= '0' && *run <= '9')
	{
		num *= 10;
		num += sign *(*(run ++) - '0');
	}
	return (num);
}
