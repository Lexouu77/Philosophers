/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:22 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/13 17:56:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned int	ft_cnt_parts(const char *s, char c)
{
	unsigned int		cnt;
	unsigned int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			++cnt;
		}
		++s;
	}
	return (cnt);
}

static unsigned int	ft_wlen(const char *s, char c)
{
	unsigned int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		++len;
		++s;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	char				**t;
	unsigned int		nb_word;
	unsigned int		index;

	index = 0;
	nb_word = ft_cnt_parts((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_cnt_parts((const char *)s, c) + 1));
	if (!t)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			++s;
		t[index] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c));
		if (!t[index])
			return (NULL);
		s = s + ft_wlen(s, c);
		++index;
	}
	t[index] = NULL;
	return (t);
}
