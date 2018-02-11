/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:34:21 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/28 20:20:34 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_counter(char *buf, char c)
{
	int nb_w;

	nb_w = 0;
	while (*buf == c)
		buf++;
	while (*buf != '\0')
	{
		if (*buf != c && (*(buf + 1) == c || *(buf + 1) == '\0'))
			nb_w++;
		buf++;
	}
	return (nb_w);
}

static int		len(char *buf, char c)
{
	int i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != c)
		i++;
	return (i);
}

static int		write_words(char **words, char *buf, char c, int nb_w)
{
	int i;
	int j;

	j = 0;
	while (nb_w > 0)
	{
		while (*buf == c)
			buf++;
		words[j] = (char*)malloc(sizeof(char) * len(buf, c) + 1);
		if (words[j] == NULL)
			return (1);
		i = 0;
		while (*buf != '\0' && *buf != c)
		{
			words[j][i] = *buf;
			i++;
			buf++;
		}
		words[j][i] = '\0';
		j++;
		nb_w--;
	}
	words[j] = 0;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*buf;
	char	**words;
	int		nb_w;

	if (!s)
		return (NULL);
	buf = (char*)s;
	nb_w = words_counter(buf, c);
	words = (char**)malloc(sizeof(char*) * nb_w + 1);
	if (words == NULL)
		return (NULL);
	if (write_words(words, buf, c, nb_w))
		return (NULL);
	return (words);
}
