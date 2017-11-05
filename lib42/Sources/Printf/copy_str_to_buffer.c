/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_to_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 04:12:24 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/15 17:04:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*unicode_char_to_str(int c, int len)
{
	char	*s;

	s = ft_strnew((size_t)len);
	if (c < 128)
		s[0] = (char)c;
	else if (c < 2048)
	{
		s[0] = (char)(((c >> 6) | 0xC0) & 0xDF);
		s[1] = (char)((c | 0x80) & 0xBF);
	}
	else if (c < 65536)
	{
		s[0] = (char)(((c >> 12) | 0xE0) & 0xEF);
		s[1] = (char)(((c >> 6) | 0x80) & 0xBF);
		s[2] = (char)((c | 0x80) & 0xBF);
	}
	else
	{
		s[0] = (char)(((c >> 18) | 0xF0) & 0xF7);
		s[1] = (char)(((c >> 12) | 0x80) & 0xBF);
		s[2] = (char)(((c >> 6) | 0x80) & 0xBF);
		s[3] = (char)((c | 0x80) & 0xBF);
	}
	return (s);
}

int			get_unicode_len(int c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else
		return (4);
}

char		*copy_str_to_buffer(char *s, size_t len)
{
	size_t	i;

	i = 0;
	if (!g_buffer)
		malloc_buffer(len);
	if (g_len + len < g_m_len)
		resize_buffer(len);
	while (i < len)
	{
		g_buffer[g_len + i] = s[i];
		i++;
	}
	g_len += i;
	return (s + i);
}

void		copy_char_to_buffer(char c)
{
	if (!g_buffer)
		malloc_buffer(1);
	if (g_len + 1 < g_m_len)
		resize_buffer(1);
	g_buffer[g_len++] = c;
}

void		copy_unicode_char_to_buffer(int c)
{
	char		*s;
	const	int	len = get_unicode_len(c);

	s = unicode_char_to_str(c, len);
	copy_str_to_buffer(s, (size_t)len);
	free(s);
}
