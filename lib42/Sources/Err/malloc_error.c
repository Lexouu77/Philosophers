/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:50:55 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 12:54:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	malloc_error(const char *file, const char *function)
{
	write(2, "Malloc Error in : ", 18);
	write(2, file, ft_strlen(file));
	write(2, " in : ", 6);
	write(2, function, ft_strlen(function));
	write(2, "\n", 1);
	exit(-1);
}

/*
** faire une struct globale qui choppe le nom de la fonction pour la tracer
** et si error j'affiche toutes les fonctions ou je suis passe ou en reverse ?
*/
