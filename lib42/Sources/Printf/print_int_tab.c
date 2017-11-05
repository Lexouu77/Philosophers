/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:35 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 08:41:31 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*itoa_b(int nb)
{
	char		*str;
	int			size;
	int			n;

	size = 1;
	if (nb < 0)
	{
		n = -nb;
		size++;
	}
	else
		n = nb;
	while (n /= 10)
		++size;
	str = ft_strnew((size_t)size);
	n = nb < 0 ? -nb : nb;
	while (--size >= 0)
	{
		str[size] = n % 10 + 48;
		n /= 10;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

void			print_int_tab(va_list *va, t_printf_flag *flag)
{
	int		*x;
	int		len;

	x = va_arg(*va, int*);
	len = va_arg(*va, int);
	while (len)
	{
		flag->converted_number = itoa_b(*x++);
		STB(flag->converted_number, ft_strlen(flag->converted_number));
		free(flag->converted_number);
		if (--len)
			CTB(32);
	}
}
