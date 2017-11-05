/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:07:36 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/16 14:20:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		malloc_buffer(size_t len)
{
	size_t	m_len;

	m_len = 0;
	while (m_len < len)
		m_len += PRINTF_BUFF_SIZE;
	g_m_len = m_len;
	if (!(g_buffer = malloc(sizeof(char) * m_len)))
		MALLOC_ERROR;
}
