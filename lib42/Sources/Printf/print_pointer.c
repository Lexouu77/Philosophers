/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:36 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 08:03:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	get_info(t_printf_flag *flag)
{
	if (flag->nb_max_char > (int)ft_strlen(flag->converted_number))
	{
		flag->nb_min_char -= (2 + flag->nb_max_char);
		flag->nb_max_char -= ft_strlen(flag->converted_number);
		if (flag->converted_number[0] == 48)
			++flag->nb_max_char;
	}
	else
	{
		flag->nb_max_char = 0;
		flag->nb_min_char -= (2 + ft_strlen(flag->converted_number));
	}
}

void			print_pointer(t_printf_flag *flag, va_list *va)
{
	void	*x;

	x = va_arg(*va, void*);
	flag->converted_number = itoa_base(x, 16, flag->type);
	flag->i = -1;
	get_info(flag);
	if (flag->zero)
		STB("0x", 2);
	while (!flag->minus &&
			flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		flag->zero ? CTB(48) : CTB(32);
	if (!flag->zero)
		STB("0x", 2);
	flag->i = -1;
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		CTB(48);
	if (!flag->is_precision_here || (flag->is_precision_here &&
				flag->converted_number[0] != 48))
		STB(flag->converted_number, ft_strlen(flag->converted_number));
	flag->i = -1;
	while (flag->minus &&
			flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		CTB(32);
	free(flag->converted_number);
}
