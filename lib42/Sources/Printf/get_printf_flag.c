/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:02:14 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 12:51:31 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_zero_or_space_or_hash(t_printf_flag *flag, char *str)
{
	if (*str == 32)
		flag->space = 1;
	else if (*str == 48)
		flag->zero = 1;
	else
		flag->hash = 1;
	return (++str);
}

char		*get_operator(t_printf_flag *flag, char *str)
{
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			flag->minus = 1;
		if (*str == 43)
			flag->plus = 1;
		++str;
	}
	return (str);
}

char		*get_precision(t_printf_flag *flag, char *str)
{
	if (flag->dot_star)
	{
		while (FT_ISDIGIT(*str))
			++str;
		return (str);
	}
	flag->is_precision_here = 1;
	ft_bzero(flag->precision, 10);
	if (!FT_ISDIGIT(*str))
	{
		flag->nb_max_char = 0;
		return (str);
	}
	flag->i = -1;
	--str;
	while (FT_ISDIGIT(*++str))
		flag->precision[++flag->i] = *str;
	flag->nb_max_char = ft_atoi(flag->precision);
	return (str);
}

char		*get_min_area_size(t_printf_flag *flag, char *str)
{
	if (flag->star)
	{
		while (FT_ISDIGIT(*str))
			++str;
		return (str);
	}
	ft_bzero(flag->min_area_size, 10);
	flag->i = -1;
	--str;
	while (FT_ISDIGIT(*++str))
		flag->min_area_size[++flag->i] = *str;
	flag->nb_min_char = ft_atoi(flag->min_area_size);
	flag->is_min_area_size_here = 1;
	return (str);
}
