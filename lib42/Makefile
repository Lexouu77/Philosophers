# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2017/02/23 13:25:37 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Basics.

NAME = libftprintf.a

CC = clang

RM = rm -f

## Flags.

CFLAGS = -Wall -Werror -Wextra

SFLAGS = -Weverything

OFLAGS = -O3 -march=native

DFLAGS = -g3 -fsanitize=address

## Lib/Header.

HEADER_PATH = ./includes

HEADER_FILE = libftprintf.h
HEADER_FILE += libftprintf_struct.h
HEADER_FILE += ft_printf.h
HEADER_FILE += ft_printf_struct.h

HEADER = $(HEADER_FILE:%.h=$(HEADER_PATH)/%.h)

LIB = ./libftprintf/libftprintf.a

## Objects/Sources.


OBJ_PATH = Objects
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

SRC_PATH = Sources
SRC_SUBDIR += Err
SRC_SUBDIR += Maths
SRC_SUBDIR += Memory
SRC_SUBDIR += Printf
SRC_SUBDIR += Read
SRC_SUBDIR += Std_lib
SRC_SUBDIR += String
SRC_SUBDIR += Write

vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))

# STD_LIB

SRC += ft_atoi.c
SRC += ft_itoa.c
SRC += itoa_base.c

# PRINTF

SRC += cast_normal_integer.c
SRC += copy_str_to_buffer.c
SRC += display_var.c
SRC += ft_printf.c
SRC += ft_printf_buffed.c
SRC += get_ansi_code.c
SRC += get_nb_min_char.c
SRC += get_printf_flag.c
SRC += get_printf_spe_flag.c
SRC += get_sign.c
SRC += get_sub_specifier.c
SRC += loop_on_str.c
SRC += malloc_buffer.c
SRC += print_binary.c
SRC += print_char.c
SRC += print_int_tab.c
SRC += print_normal_char.c
SRC += print_normal_integer.c
SRC += print_normal_string.c
SRC += print_pointer.c
SRC += print_str_tab.c
SRC += print_unicode_char.c
SRC += print_unicode_string.c
SRC += resize_buffer.c
SRC += stock_n.c

# MEMORY

SRC += byte_swap.c
SRC += ft_bzero.c
SRC += ft_memalloc.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memmove.c
SRC += ft_memset.c

# STRING

SRC += ft_strcat.c
SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strdup.c
SRC += ft_strjoin.c
SRC += ft_strjoinsep.c
SRC += ft_strlen.c
SRC += ft_strmrepl.c
SRC += ft_strmxlen.c
SRC += ft_strncmp.c
SRC += ft_strncpy.c
SRC += ft_strndup.c
SRC += ft_strnew.c
SRC += ft_strnjoin.c
SRC += ft_strnmchr.c
SRC += ft_strnocasecmp.c
SRC += ft_strnocasencmp.c
SRC += ft_strrepl.c
SRC += ft_strslen.c
SRC += ft_strsplit.c
SRC += ft_strsub.c
SRC += ft_strtrim.c
SRC += ft_strxcmp.c
SRC += ft_strxdup.c
SRC += ft_strxlen.c

# ERROR

SRC += leave_error.c
SRC += malloc_error.c

# MATHS

SRC += fctrl.c

# WRITE

SRC += ft_putchar.c
SRC += ft_putendl.c
SRC += ft_putnbr.c
SRC += ft_putstr.c

# READ

SRC += get_next_line.c

NORMINETTE_TEST := $(shell norminette $(SRC_PATH) $(HEADER_PATH) | grep -B 1 Error)

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $(NAME)

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)

$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(SFLAGS) -I $(HEADER_PATH)

$(OBJ_PATH):
	@-mkdir -p $@

clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
ifeq ($(NORMINETTE_TEST), )
	@echo "Everything ok!"
else
	@norminette $(SRC_PATH) $(HEADER_PATH) | grep -B 1 Error
endif

watch:
	watch "make norme" "20"

test: all
	$(CC) main.c -L . -lftprintf
	./a.out

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme watch function
