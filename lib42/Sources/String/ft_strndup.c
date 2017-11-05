/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:18 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 12:42:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dest;
	int		i;

	i = -1;
	if (!(dest = malloc(sizeof(char) * (unsigned)n + 1)))
		MALLOC_ERROR;
	while (s[++i] && n--)
		dest[i] = s[i];
	dest[i] = 0;
	return (dest);
}
