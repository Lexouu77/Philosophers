/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 14:51:05 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strxdup(const char *s, char c)
{
	char				*dest;
	int					i;
	unsigned int		len;

	len = 0;
	i = -1;
	while (s[len] && s[len] != c)
		++len;
	dest = (char*)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while ((unsigned int)++i < len)
		dest[i] = s[i];
	dest[len] = 0;
	return (dest);
}
