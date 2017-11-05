/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/16 11:54:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				p;
	const unsigned char	*x;

	x = s;
	p = 0;
	while (p < n)
	{
		if (x[p] == (const unsigned char)c)
			return ((void*)((uintptr_t)x + (uintptr_t)p));
		p++;
	}
	return (0);
}
