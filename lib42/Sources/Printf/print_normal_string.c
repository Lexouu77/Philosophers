/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_normal_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:38 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/15 20:01:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		set_precision(t_printf_flag *flag, int len)
{
	flag->nb_max_char = 0;
	return (len);
}

static	int		get_nb_min_char_string(t_printf_flag *flag, char *str)
{
	int	len2;

	len2 = (int)ft_strlen(str);
	if (flag->is_precision_here)
	{
		if (flag->nb_max_char > flag->nb_min_char && flag->nb_min_char < len2)
			flag->nb_min_char = 0;
		else
			flag->nb_min_char -= (len2 <= flag->nb_max_char) ? (len2) :
				flag->nb_max_char;
		if (flag->nb_max_char > len2)
			return (set_precision(flag, len2));
		if (len2 != 0 && flag->nb_max_char < len2)
			len2 = flag->nb_max_char;
		flag->nb_max_char -= (flag->nb_max_char > len2) ? len2 :
			flag->nb_max_char;
		if (!flag->is_min_area_size_here && flag->nb_max_char == len2)
			flag->nb_max_char = 0;
		return (len2);
	}
	else
		flag->nb_min_char -= (len2);
	return (len2);
}

void			print_normal_string(va_list *va, t_printf_flag *flag,
		int null_str)
{
	void		*x;
	int			len;

	if (flag->sub_specifier[0] == 'l' && !flag->sub_specifier[1])
	{
		print_unicode_string(va, flag);
		return ;
	}
	x = (null_str) ? NULL : va_arg(*va, void*);
	if (!x)
		x = "(null)";
	flag->i = -1;
	len = get_nb_min_char_string(flag, (char *)x);
	while (!flag->minus && flag->is_min_area_size_here &&
			++flag->i < flag->nb_min_char)
		flag->zero ? CTB(48) : CTB(32);
	flag->i = -1;
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		CTB(32);
	if (len)
		STB((char*)x, (size_t)len);
	flag->i = -1;
	while (flag->minus && flag->is_min_area_size_here &&
			++flag->i < flag->nb_min_char)
		CTB(32);
}
