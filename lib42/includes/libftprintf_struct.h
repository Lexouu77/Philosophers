/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:52:47 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 15:03:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_STRUCT_H
# define LIBFTPRINTF_STRUCT_H

# include "libftprintf.h"

typedef struct		s_gnl
{
	int				fd;
	int				start;
	char			*buffer;
	long			end;
	struct s_gnl	*next;
}					t_gnl;

#endif
