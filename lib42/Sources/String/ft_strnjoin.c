/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:19 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 12:44:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char			*ns;
	const	size_t	len = ft_strlen(s1);

	if (!s1)
		return (ft_strndup(s2, n));
	if (s1 && s2)
	{
		ns = ft_strnew(len + (unsigned)n);
		ns = ft_strcpy(ns, s1);
		ns = ft_strcat(ns + len, s2);
		return (ns - len);
	}
	return (NULL);
}
