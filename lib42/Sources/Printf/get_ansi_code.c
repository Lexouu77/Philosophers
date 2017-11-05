/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ansi_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:28 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 12:52:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_custom_value(char *str)
{
	while (*str && FT_ISDIGIT(*str))
		CTB(*str++);
	CTB('m');
	return (str);
}

static char	*apply_fg(char *str)
{
	if (!ft_strncmp(str, "RED", 3))
		STB(ANSI_FG_RED, 5);
	if (!ft_strncmp(str, "BLU", 3))
		STB(ANSI_FG_BLUE, 5);
	if (!ft_strncmp(str, "GRE", 3))
		STB(ANSI_FG_GREEN, 5);
	if (!ft_strncmp(str, "YEL", 3))
		STB(ANSI_FG_YELLOW, 5);
	if (!ft_strncmp(str, "MAG", 3))
		STB(ANSI_FG_MAGENTA, 5);
	if (!ft_strncmp(str, "CYA", 3))
		STB(ANSI_FG_CYAN, 5);
	if (!ft_strncmp(str, "WHI", 3))
		STB(ANSI_FG_WHITE, 5);
	if (!ft_strncmp(str, "CSM", 3))
	{
		STB(ANSI_FG_CUSTOM, 7);
		return (get_custom_value(str + 3));
	}
	return (str + 3);
}

static char	*apply_bg(char *str)
{
	if (!ft_strncmp(str, "RED", 3))
		STB(ANSI_BG_RED, 5);
	if (!ft_strncmp(str, "BLU", 3))
		STB(ANSI_BG_BLUE, 5);
	if (!ft_strncmp(str, "GRE", 3))
		STB(ANSI_BG_GREEN, 5);
	if (!ft_strncmp(str, "YEL", 3))
		STB(ANSI_BG_YELLOW, 5);
	if (!ft_strncmp(str, "MAG", 3))
		STB(ANSI_BG_MAGENTA, 5);
	if (!ft_strncmp(str, "CYA", 3))
		STB(ANSI_BG_CYAN, 5);
	if (!ft_strncmp(str, "WHI", 3))
		STB(ANSI_BG_WHITE, 5);
	if (!ft_strncmp(str, "CSM", 3))
	{
		STB(ANSI_BG_CUSTOM, 7);
		return (get_custom_value(str + 3));
	}
	return (str + 3);
}

static char	*apply_sp(char *str, t_printf_flag *flag)
{
	if (!ft_strncmp(str, "RST", 3))
		flag->reset_ansi = 1;
	if (!ft_strncmp(str, "BOL", 3))
		STB(ANSI_BOLD, 4);
	if (!ft_strncmp(str, "UND", 3))
		STB(ANSI_UNDERLIGNED, 4);
	if (!ft_strncmp(str, "REV", 3))
		STB(ANSI_REVERSE_COLOR, 4);
	if (!ft_strncmp(str, "FGR", 3))
		flag->reset_fg = 1;
	if (!ft_strncmp(str, "BGR", 3))
		flag->reset_bg = 1;
	return (str + 3);
}

char		*get_ansi_code(t_printf_flag *flag, char *str)
{
	str++;
	while (*str && *str != ']')
	{
		if (*str == ',')
			str++;
		else if (!ft_strncmp("FG_", str, 3))
			str = apply_fg(str + 3);
		else if (!ft_strncmp("BG_", str, 3))
			str = apply_bg(str + 3);
		else if (!ft_strncmp("SP_", str, 3))
			str = apply_sp(str + 3, flag);
		else
			str++;
	}
	return (str + 1);
}
