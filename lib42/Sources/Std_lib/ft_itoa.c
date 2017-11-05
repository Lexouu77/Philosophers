/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/09 15:17:21 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	count_digits(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		++i;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	u_nbr;

	len = count_digits(n);
	if (n < 0)
	{
		u_nbr = (unsigned int)-n;
		++len;
	}
	else
		u_nbr = (unsigned int)n;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		MALLOC_ERROR;
	str[len] = 0;
	str[--len] = u_nbr % 10 + '0';
	while (u_nbr /= 10)
		str[--len] = u_nbr % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
