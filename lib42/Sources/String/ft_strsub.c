/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 12:41:21 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	char	*begin_ns;

	if (!s)
		return (NULL);
	ns = ft_strnew(len);
	if (!ns)
		return (NULL);
	begin_ns = ns;
	while (start--)
		++s;
	while (*s && len--)
		*ns++ = *s++;
	return (begin_ns);
}
