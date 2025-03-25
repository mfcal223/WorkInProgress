# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 11:40:56 by mpiantan          #+#    #+#              #
#    Updated: 2025/03/24 14:56:02 by mpiantan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) -g
RM = rm -f

SRC_DIR = sources
INC_DIR = includes
LIB_DIR = libft

SRC_FILES = $(SRC_DIR)/minishell.c \
	$(SRC_DIR)/signal_handler.c \

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

BONUS_SRC_FILES = 

BONUS_OBJ_FILES = $(BONUS_SRC_FILES:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

LIBFT = $(LIB_DIR)/libft.a 

NAME = minishell
BONUS_NAME = minishell_bonus


all: $(LIBFT) $(NAME)

$(LIBFT):
	make all -C $(LIB_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -lreadline -lhistory -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)
	
$(BONUS_NAME): $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) $(LIBFT) -lreadline -lhistory -o $(BONUS_NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	make clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C $(LIB_DIR)

re: fclean all


.PHONY: all clean fclean re bonus
