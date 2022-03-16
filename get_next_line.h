/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:31:36 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/08/23 12:15:21 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/resource.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

int		prev_gnl(char **pl, char **l);
char	*line_starto(int *cf, char **pl, char **l, int fd);
char	*add_line(char **l, ssize_t delta, int *cf, char *buf);

size_t	ft_strlen(const char *str);
char	*ft_strnchr(const char *s, int c, size_t range);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
ssize_t	line_ended(char *buf, int delta);

# define MAX_FD RLIMIT_NOFILE

#endif
