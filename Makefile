# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 17:37:30 by cmissy            #+#    #+#              #
#    Updated: 2020/02/16 17:37:30 by cmissy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cmissy.filler

LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a

VISUAL_DIR = ./visualizer
VISUAL = ./visualizer/visual

INCLUDES = ./includes
HEADER = $(INCLUDES)/filler.h

# dirs
DIR_S = srcs
DIR_O = objs

# files
C_FILES = main.c \
		t_flr.c \
		fill_heat_map.c \
		fill_map.c \
		fill_piece.c \
		find_solution.c \

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC_LIBS = -L $(LIB_DIR) -lft
INC_HEADERS = -I $(INCLUDES) -I $(LIB_DIR)

.PHONY: all clean fclean re force

all: $(NAME) $(VISUAL)

$(NAME): $(LIB) $(DIR_O) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INC_HEADERS) $(INC_LIBS) -o $@

$(LIB): force
	make -C $(LIB_DIR)

$(DIR_O):
	mkdir -p objs

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIB_DIR) -c ./$< -o $@

$(VISUAL): force
	make -C $(VISUAL_DIR)

clean:
	rm -rf $(DIR_O)
	make clean -C $(LIB_DIR)
	make clean -C $(VISUAL_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(VISUAL)
	rm -f $(LIB)

re: fclean all