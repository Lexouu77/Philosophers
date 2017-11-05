# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2017/11/01 16:46:21 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Basics.

NAME = philosophers
CC = clang
#CC= g++
RM = rm -f

## Flags.

CFLAGS = -Wall -Werror -Wextra
SFLAGS = -Weverything
OFLAGS = -O3 -march=native
DFLAGS = -g3 -fsanitize=address
CFLAGS += $(SFLAGS)

CFLAGS += -I $(HEADER_PATH)

## Lib/Header.

HEADER_PATH = Includes
HEADER_FILE = philosophers.h
HEADER = $(HEADER_FILE:%.h=$(HEADER_PATH)/%.h)

#HEADER = $(HEADER_FILE:%.hpp=$(HEADER_PATH)/%.hpp)

LIB = ./lib42/libftprintf.a

LIB_LINKER = -L ./lib42/ -lftprintf -lpthread

#LIB_HEADER.

## Objects/Sources.

SRC_PATH = Sources
SRC_SUBDIR += .

SRC += philosophers.c
SRC += play_game.c
SRC += manage_game.c

OBJ_PATH = Objects
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

#OBJECTS = $(addprefix $(OBJ_PATH)/, $(SRC:%.cpp=%.o))

vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))

NORMINETTE_TEST := $(shell norminette $(SRC_PATH) $(HEADER_PATH) | grep -B1 -e Error -e Warning)

#Not working as intended i guess ?

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJECTS) | $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINKER)

$(LIB) :
	Make -C lib42

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)

$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER_PATH)

$(OBJ_PATH):
	@-mkdir -p $@

clean:
	$(RM) -r $(OBJ_PATH)
	Make clean -C lib42

fclean: clean
	$(RM) $(NAME)
	Make fclean -C lib42

re: fclean all

norme:
ifeq ($(NORMINETTE_TEST), )
	@echo "Everything ok!"
else
	@norminette $(SRC_PATH) $(HEADER_PATH) | grep -B 1 Error
endif

watch:
	watch "make norme" "20"

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme watch function
