/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/11 20:13:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *str1 = (const char*)s1;
	const char *str2 = (const char*)s2;

	++n;
	while (--n)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		++str1;
		++str2;
	}
	return (0);
}
