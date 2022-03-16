/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:25:11 by  jlucas-f         #+#    #+#             */
/*   Updated: 2021/08/23 12:14:07 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	prev_gnl(char **pl, char **l)
{
	size_t	prev_end;
	size_t	prev_size;
	char	*temp;

	if (*pl == NULL)
		return (0);
	prev_size = ft_strlen(*pl);
	prev_end = line_ended(*pl, prev_size);
	if (!prev_end)
	{
		*l = malloc(prev_size + 1);
		ft_strlcpy(*l, *pl, prev_size + 1);
		free (*pl);
		*pl = NULL;
		return (21);
	}
	*l = malloc(prev_end + 1);
	ft_strlcpy(*l, *pl, prev_end + 1);
	temp = *pl;
	*pl = malloc(prev_size - prev_end + 1);
	ft_strlcpy(*pl, temp + prev_end, prev_size - prev_end + 1);
	free(temp);
	return (42);
}

char	*add_line(char **l, ssize_t delta, int *cf, char *buf)
{
	size_t	buf_len;
	size_t	prev_len;
	char	*pl;

	buf_len = line_ended(buf, delta);
	if (buf_len == 0)
		buf_len = delta;
	pl = *l;
	if (pl == NULL)
		prev_len = 0;
	else
		prev_len = ft_strlen (pl);
	*l = malloc (prev_len + buf_len + 1);
	if (*l == NULL)
		return (NULL);
	ft_strlcpy(*l, pl, prev_len + 1);
	if (pl == NULL)
		*l[0] = '\0';
	else
		free (pl);
	ft_strlcat(*l, buf, prev_len + buf_len + 1);
	if (delta < BUFFER_SIZE || line_ended(buf, delta))
		*cf = 42;
	return (*l);
}

ssize_t	loop_read(int *cf, char *b, char **pl, char **l)
{
	ssize_t	delta;

	while (cf[0] != 42)
	{
		delta = read(cf[1], b, BUFFER_SIZE);
		if (delta == 0 || delta == -1)
		{
			free(b);
			if (delta == -1)
				*l = NULL;
			if (*pl != NULL)
			{
				free (*pl);
				*pl = NULL;
			}
			return (0);
		}
		b[delta] = '\0';
		*l = add_line(l, delta, cf, b);
		if (*l == NULL)
			break ;
	}
	return (delta);
}

char	*endgame(char *buf, ssize_t delta, char *line, char **pl)
{
	ssize_t	found_break;

	if (delta == 0 || line == NULL)
		return (line);
	found_break = line_ended(buf, delta);
	if (delta < BUFFER_SIZE && !found_break)
	{
		if (*pl != NULL)
		{
			free (*pl);
			*pl = NULL;
		}
	}
	else if (found_break)
	{
		if (*pl == NULL)
			*pl = malloc(delta - found_break + 1);
		if (*pl == NULL)
			return (NULL);
		ft_strlcpy(*pl, buf + found_break, delta - found_break + 1);
	}
	free(buf);
	if (line != NULL && line[0] == '\0')
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	int			cest_fini[2];
	char		*buf;
	static char	*prev_line;
	char		*line;
	ssize_t		delta;

	if (fd < 0 || fd > MAX_FD || read(fd, NULL, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (prev_line != NULL && prev_line[0] == '\0')
	{
		free(prev_line);
		prev_line = NULL;
	}
	cest_fini[0] = prev_gnl(&prev_line, &line);
	if (cest_fini[0] == 42)
		return (line);
	else if (cest_fini[0] != 21)
		line = NULL;
	cest_fini[1] = fd;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	delta = loop_read(cest_fini, buf, &prev_line, &line);
	line = endgame(buf, delta, line, &prev_line);
	return (line);
}
