/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:44:53 by jlucas-f          #+#    #+#             */
/*   Updated: 2021/06/14 16:50:07 by  jlucas-f        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] != '\0')
			++count;
		while ((s[i] != '\0') && (s[i] != c))
			++i;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, n + 1);
	return (str);
}

char	**lili_cantou(char **matrix, size_t *word_ind)
{
	size_t	x;

	x = 0;
	while (x < *word_ind)
	{
		free(matrix[x]);
		++x;
	}
	free(matrix);
	return (NULL);
}

static char	**split_core(char const *s, char c, size_t *word_ind, char **matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		j = i;
		while ((s[i] != '\0') && (s[i] != c))
			++i;
		if (i > j)
		{
			matrix[*word_ind] = ft_strndup(s + j, i - j);
			if (matrix[*word_ind] == NULL)
				return (lili_cantou(matrix, word_ind));
			++*word_ind;
		}
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_i;
	size_t	*word_ind;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	matrix = malloc(sizeof(char *) * count_words(s, c) + 1);
	if (matrix == NULL)
		return (NULL);
	word_ind = &word_i;
	*word_ind = 0;
	matrix = split_core(s, c, word_ind, matrix);
	if (matrix != NULL)
		matrix[*word_ind] = NULL;
	return (matrix);
}
