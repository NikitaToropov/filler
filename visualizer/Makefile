# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 17:37:13 by cmissy            #+#    #+#              #
#    Updated: 2020/02/16 17:37:25 by cmissy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

LIB_DIR = ../libft
LIB = $(LIB_DIR)/libft.a

# files
C_FILES = main.c \

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC_LIBS = -L $(LIB_DIR) -lft
INC_HEADERS = -I $(LIB_DIR)

.PHONY: all clean fclean re force

all: $(NAME)

$(NAME): $(LIB) $(C_FILES)
	$(CC) $(FLAGS) $(C_FILES) $(INC_HEADERS) $(INC_LIBS) -o $@

$(LIB): force
	make -C $(LIB_DIR)

clean:
	make fclean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all