/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:01:49 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/15 17:17:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

typedef struct		s_printf_flag
{
	char			precision[10];
	char			min_area_size[10];
	int				nb_max_char;
	int				hash;
	int				i;
	int				nb_min_char;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	char			type;
	char			sign;
	char			is_min_area_size_here;
	char			is_precision_here;
	char			sub_specifier[2];
	char			reset_fg;
	char			reset_ansi;
	char			reset_bg;
	char			star;
	char			dot_star;
	char			padding_byte;
	char			*converted_number;
}					t_printf_flag;

#endif
