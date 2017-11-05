/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:11 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/23 13:37:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;

	if (s1 && s2)
	{
		if (!(ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			MALLOC_ERROR;
		ns = ft_strcpy(ns, s1);
		ns = ft_strcat(ns, s2);
		return (ns);
	}
	return (NULL);
}
