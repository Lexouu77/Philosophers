/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:34 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 04:53:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(t_printf_flag *flag)
{
	flag->i = -1;
	if (!flag->is_min_area_size_here)
	{
		CTB(flag->type);
		return ;
	}
	else
	{
		while (!flag->minus && ++flag->i < flag->nb_min_char - 1)
			flag->zero ? CTB(48) : CTB(32);
		CTB(flag->type);
		while (flag->minus && ++flag->i < flag->nb_min_char - 1)
			CTB(32);
	}
}
