/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:34 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 08:39:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_binary(t_printf_flag *flag, va_list *va)
{
	void				*x;

	x = va_arg(*va, void*);
	flag->converted_number = itoa_base(x, 2, 'c');
	STB((flag->type == 'b') ? "0b" : "0B", 2);
	STB(flag->converted_number, ft_strlen(flag->converted_number));
	free(flag->converted_number);
}
