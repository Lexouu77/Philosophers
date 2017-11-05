/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:12 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/23 13:41:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoinsep(const char *s1, const char *s2, char sep)
{
	char			*ns;
	const	size_t	len = ft_strlen(s1);

	if (s1 && s2)
	{
		if (!(ns = ft_strnew(len + ft_strlen(s2) + 1)))
			MALLOC_ERROR;
		ns = ft_strcpy(ns, s1);
		ns[len] = sep;
		ns = ft_strcat(ns, s2);
		return (ns);
	}
	return (NULL);
}
