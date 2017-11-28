# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 07:29:36 by oozkaya           #+#    #+#              #
#    Updated: 2017/11/28 17:14:31 by oozkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = includes
INC_LIB = ./
INCS = -I $(LIB_PATH)/$(INC_LIB) -I $(INC_DIR)

SRC_DIR = src
SRC = main.c read.c

OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

C_NO = "\033[00m"
C_DONE = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
DONE = $(C_DONE)DONE$(C_NO)

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling -> " $(NAME) $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<
	@echo "Linking -> " $< $(DONE)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning -> " $(NAME) $(DONE)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Deleting -> " $(NAME) $(DONE)

re: fclean all
