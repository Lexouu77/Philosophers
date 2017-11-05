/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:35 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 09:11:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_normal_char(va_list *va, t_printf_flag *flag)
{
	void	*x;
	char	transformed_x;

	if (flag->sub_specifier[0] == 'l' && !flag->sub_specifier[1])
	{
		print_unicode_char(va, flag);
		return ;
	}
	flag->i = -1;
	x = va_arg(*va, void*);
	transformed_x = (char)x;
	if (!flag->is_min_area_size_here)
	{
		CTB(transformed_x);
		return ;
	}
	else
	{
		while (!flag->minus && ++flag->i < flag->nb_min_char - 1)
			flag->zero ? CTB(48) : CTB(32);
		CTB(transformed_x);
		while (flag->minus && ++flag->i < flag->nb_min_char - 1)
			flag->zero ? CTB(48) : CTB(32);
	}
}
