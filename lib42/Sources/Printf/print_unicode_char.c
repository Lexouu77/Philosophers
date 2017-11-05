/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:37 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 06:16:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_unicode_char(va_list *va, t_printf_flag *flag)
{
	void	*x;
	int		len;

	flag->i = -1;
	x = va_arg(*va, void*);
	len = get_unicode_len((int)x);
	if (!flag->is_min_area_size_here)
	{
		copy_unicode_char_to_buffer((int)x);
		return ;
	}
	else
	{
		while (!flag->minus && ++flag->i < flag->nb_min_char - len)
			flag->zero ? CTB(48) : CTB(32);
		copy_unicode_char_to_buffer((int)x);
		while (flag->minus && ++flag->i < flag->nb_min_char - len)
			flag->zero ? CTB(48) : CTB(32);
	}
}
