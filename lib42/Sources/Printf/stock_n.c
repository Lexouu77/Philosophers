/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:39 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 08:28:43 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			stock_n(va_list *va, t_printf_flag *flag)
{
	long long	*n;

	n = va_arg(*va, void*);
	if (flag->sub_specifier[0] == 'h')
	{
		if (flag->sub_specifier[1] == 'h')
			*n = (char)g_len;
		*n = (short int)g_len;
	}
	if (flag->sub_specifier[0] == 'l')
	{
		if (flag->sub_specifier[1] == 'l')
			*n = (long long)g_len;
		*n = (long)g_len;
	}
	if (flag->sub_specifier[0] == 'j')
		*n = (long long)g_len;
	if (flag->sub_specifier[0] == 'z')
		*n = (long long)g_len;
	*n = (long long)g_len;
}
