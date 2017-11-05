/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:37 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 08:42:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_str_tab(va_list *va, t_printf_flag *flag)
{
	char	**s;
	int		len;

	s = va_arg(*va, char**);
	len = va_arg(*va, int);
	while (len)
	{
		if (*s)
			flag->converted_number = ft_strdup(*s);
		else
			flag->converted_number = ft_strdup("(null)");
		STB(flag->converted_number, ft_strlen(flag->converted_number));
		free(flag->converted_number);
		++s;
		if (--len)
			CTB('\n');
	}
}
