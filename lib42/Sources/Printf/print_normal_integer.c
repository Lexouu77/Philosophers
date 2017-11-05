/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:36 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 12:52:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_without_minus(t_printf_flag *flag)
{
	if (flag->zero && (flag->type == 'x' || flag->type == 'X') &&
			flag->hash && flag->converted_number[0] != 48)
		STB((flag->type == 'x') ? "0x" : "0X", 2);
	if (flag->zero && flag->plus && flag->type != 'u' && flag->type != 'U')
		CTB(flag->sign);
	if (flag->space && flag->type != 'u' && flag->type != 'U')
		CTB(32);
	while (flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		flag->zero ? CTB(48) : CTB(32);
	flag->i = -1;
	if (!flag->zero && flag->plus && flag->type != 'u' && flag->type != 'U')
		CTB(flag->sign);
	if (!flag->zero && (flag->type == 'x' || flag->type == 'X') &&
			flag->hash && flag->converted_number[0] != 48)
		STB((flag->type == 'x') ? "0x" : "0X", 2);
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		CTB(48);
	if ((flag->type == 'o' || flag->type == 'O') && flag->hash)
		CTB(48);
	if (!flag->is_precision_here || (flag->is_precision_here &&
				flag->converted_number[0] != 48))
		STB(flag->converted_number, ft_strlen(flag->converted_number));
}

static	void	print_with_minus(t_printf_flag *flag)
{
	if ((flag->type == 'o' || flag->type == 'O') && flag->hash)
		CTB(48);
	if ((flag->type == 'x' || flag->type == 'X') && flag->hash &&
			flag->converted_number[0] != 48)
		STB((flag->type == 'x') ? "0x" : "0X", 2);
	if (flag->plus && flag->type != 'u' && flag->type != 'U')
		CTB(flag->sign);
	if (flag->space && flag->type != 'u' && flag->type != 'U')
		CTB(32);
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		CTB(48);
	if (!flag->is_precision_here || (flag->is_precision_here &&
				flag->converted_number[0] != 48))
		STB(flag->converted_number, ft_strlen(flag->converted_number));
	flag->i = -1;
	while (flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		CTB(32);
}

void			print_normal_integer(va_list *va, t_printf_flag *flag)
{
	void				*x;
	unsigned long long	c_x;

	x = va_arg(*va, void*);
	x = cast_normal_integer(flag, x);
	c_x = (unsigned long long)(void*)get_sign(x, flag);
	if (flag->type == 'd' || flag->type == 'i' || flag->type == 'u' ||
			flag->type == 'U' || flag->type == 'D')
		flag->converted_number = itoa_base((void*)c_x, 10, flag->type);
	if (flag->type == 'x' || flag->type == 'X')
		flag->converted_number = itoa_base((void*)c_x, 16, flag->type);
	if (flag->type == 'o' || flag->type == 'O')
		flag->converted_number = itoa_base((void*)c_x, 8, flag->type);
	get_nb_min_char(flag, flag->converted_number);
	flag->i = -1;
	if (flag->minus)
		print_with_minus(flag);
	if (!flag->minus)
		print_without_minus(flag);
	free(flag->converted_number);
}
