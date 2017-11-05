/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:05:05 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/28 17:09:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	g_len = 0;
size_t	g_m_len = 0;
char	*g_buffer = NULL;

int	ft_printf(char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (ft_printf_buffed(1, 1, NULL, NULL));
	va_start(args, format);
	i = ft_printf_buffed(1, 1, format, args);
	va_end(args);
	return (i);
}

int	ft_printf_fd(int fd, char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (ft_printf_buffed(1, 1, NULL, NULL));
	va_start(args, format);
	i = ft_printf_buffed(fd, 1, format, args);
	va_end(args);
	return (i);
}
