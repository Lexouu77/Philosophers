/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:44 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/15 20:01:59 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_alpha_var(t_printf_flag *flag, va_list *va)
{
	if (flag->type == 'c')
		print_normal_char(va, flag);
	if (flag->type == '%')
		print_char(flag);
	if (flag->type == 's')
		print_normal_string(va, flag, 0);
	if (flag->type == 'C')
		print_unicode_char(va, flag);
	if (flag->type == 'S')
		print_unicode_string(va, flag);
}

void		display_spe_var(t_printf_flag *flag, va_list *va)
{
	if (flag->type == 'n')
		stock_n(va, flag);
	else if (flag->type == 'p')
		print_pointer(flag, va);
	else if (flag->type == 'B' || flag->type == 'b')
		print_binary(flag, va);
	else if (flag->type == 'v')
		print_str_tab(va, flag);
	else if (flag->type == 'V')
		print_int_tab(va, flag);
}

void		display_numeric_var(t_printf_flag *flag, va_list *va)
{
	if (IS_NUMT(flag->type))
		print_normal_integer(va, flag);
}
