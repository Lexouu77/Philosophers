/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:09 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/09 15:07:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		MALLOC_ERROR;
	while (s[i])
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}
