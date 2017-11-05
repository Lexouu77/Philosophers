/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:21 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/11 20:21:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strrepl(char *src, char to_find, char c)
{
	int i;

	i = -1;
	while (src[++i])
		if (src[i] == to_find)
			src[i] = c;
}
