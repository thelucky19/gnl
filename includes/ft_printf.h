/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:39:53 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/08/31 19:12:15 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format_str, ...);

int	ft_printf_char(char c);
int	ft_printf_hexadec_unsigned_int(unsigned int x);
int	ft_printf_hexadec_uppercase_unsigned_int(unsigned int x);
int	ft_printf_int(int i);
int	ft_printf_ptr(void *ptr);
int	ft_printf_str(char *str);
int	ft_printf_unsigned_int(unsigned int u);

#endif