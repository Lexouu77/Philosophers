/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:21:00 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 04:39:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		resize_buffer(size_t len)
{
	char	*str;
	size_t	m_len;

	m_len = g_m_len;
	while (m_len < len + g_m_len)
		m_len += PRINTF_BUFF_SIZE;
	g_m_len = m_len;
	if (!(str = malloc(sizeof(char) * m_len)))
		MALLOC_ERROR;
	ft_memcpy(str, g_buffer, g_len);
	free(g_buffer);
	g_buffer = str;
}
