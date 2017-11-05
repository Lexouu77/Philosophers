/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 06:48:29 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/23 13:29:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <pwd.h>
# include <errno.h>
# include <sys/acl.h>
# include <termios.h>
# include <curses.h>

# include "libftprintf_struct.h"
# include "ft_printf.h"

# define BUFF_SIZE 4096

# define ANSI_RESET			"\x1b[0m"
# define ANSI_BOLD			"\x1b[1m"
# define ANSI_UNDERLIGNED	"\x1b[4m"
# define ANSI_REVERSE_COLOR	"\x1b[7m"

# define ANSI_FG_RED		"\x1b[31m"
# define ANSI_FG_GREEN		"\x1b[32m"
# define ANSI_FG_YELLOW		"\x1b[33m"
# define ANSI_FG_BLUE		"\x1b[34m"
# define ANSI_FG_MAGENTA	"\x1b[35m"
# define ANSI_FG_CYAN		"\x1b[36m"
# define ANSI_FG_WHITE		"\x1b[37m"
# define ANSI_FG_CUSTOM		"\x1b[38;5;"

# define ANSI_FG_STANDART	"\x1b[39m"

# define ANSI_BG_RED		"\x1b[41m"
# define ANSI_BG_GREEN		"\x1b[42m"
# define ANSI_BG_YELLOW		"\x1b[43m"
# define ANSI_BG_BLUE		"\x1b[44m"
# define ANSI_BG_MAGENTA	"\x1b[45m"
# define ANSI_BG_CYAN		"\x1b[46m"
# define ANSI_BG_WHITE		"\x1b[47m"
# define ANSI_BG_CUSTOM		"\x1b[48;5;"

# define ANSI_BG_STANDART	"\x1b[40m"

# define FT_ISASCII(c) (((c) & 0x80) == 0)
# define FT_ISBLANK(c) ((c) == ' ' || (c) == '\t')
# define FT_ISWHITESPACE(c) (FT_ISBLANK(c) || ((c) == '\n'))
# define FT_ISSPACE(c) ((c) == ' ' || ((unsigned)(c) - '\t') < 5U)
# define FT_ISCNTRL(c) (((c) < 0x20) || ((c) == 0x7F))
# define FT_ISDIGIT(c) ((unsigned)(c) - '0' < 10U)
# define FT_ISLOWER(c) ((unsigned)(c) - 'a' < 26U)
# define FT_ISUPPER(c) ((unsigned)(c) - 'A' < 26U)
# define FT_ISGRAPH(c) ((unsigned)(c) - '!' < 94U)
# define FT_ISPRINT(c) ((unsigned)(c) - ' ' < 95U)
# define FT_ISALPHA(c) (FT_ISLOWER(c) || FT_ISUPPER(c))
# define FT_ISALNUM(c) (FT_ISALPHA(c) || FT_ISDIGIT(c))
# define FT_ISPUNCT(c) (FT_ISGRAPH(c) && !FT_ISALNUM(c))
# define FT_TOUPPER(c) ((FT_ISLOWER(c)) ? ((c) & 0x5F) : (c))
# define FT_TOLOWER(c) ((FT_ISUPPER(c)) ? ((c) | 0x20) : (c))
# define FT_ISXDIGIT(c) (FT_ISDIGIT(c) || ((unsigned)(c) | 0x20) - 'a' < 6U)

# define MALLOC_ERROR malloc_error(__FILE__, __FUNCTION__)

/*
** STD_LIB CONVERSIONS FUNCTIONS
*/

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*itoa_base(void *x, unsigned long base, char type);

/*
** MEMORY FUNCTIONS
*/

void		*byte_swap(void *toswap, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

/*
** STRING FUNCTIONS
*/

char		*ft_strcat(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinsep(const char *s1, const char *s2, char sep);
size_t		ft_strlen(const char *s);
void		ft_strmrepl(char *src, char *to_find, char c);
size_t		ft_stmrxlen(const char *s, char *c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strndup(const char *s, int n);
char		*ft_strnew(size_t size);
char		*ft_strnjoin(char const *s1, char const *s2, int n);
int			ft_strnmchr(char *s, char *to_find, int l);
int			ft_strnocasecmp(const char *s1, const char *s2);
int			ft_strnocasencmp(const char *s1, const char *s2, int n);
void		ft_strrepl(char *src, char to_find, char c);
size_t		ft_strslen(const char *s, char *to_find);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
int			ft_strxcmp(const char *s1, const char *s2, int n);
char		*ft_strxdup(const char *s, char c);
size_t		ft_strxlen(const char *s, char c);

/*
** ERROR FUNCTIONS
*/

int			leave_error(char *str);
int			malloc_error(const char *file, const char *function);

/*
** MATHS FUNCTIONS
*/

int			fctrl(int nb);

/*
** WRITE FUNCTIONS
*/

void		ft_putchar(char c);
void		ft_putendl(char const *s);
void		ft_putnbr(int nb);
void		ft_putstr(const char *s);

/*
** READ FUNCTIONS
*/

int			get_next_line(const int fd, char **line);

#endif
