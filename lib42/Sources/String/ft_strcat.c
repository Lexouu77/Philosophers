/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/11 20:14:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		++i;
	}
	dest[len + i] = '\0';
	return (dest);
}
