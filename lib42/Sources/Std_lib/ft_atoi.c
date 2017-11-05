/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/09 15:35:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoi(const char *str)
{
	char		sign;
	int			result;
	int			i;

	sign = 0;
	result = 0;
	i = 0;
	while (str[i] && FT_ISSPACE(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			sign = 1;
	while (str[i] && FT_ISDIGIT(str[i]))
		result = result * 10 + str[i++] - 48;
	return (sign ? -result : result);
}
