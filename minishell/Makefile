# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 11:40:56 by mpiantan          #+#    #+#              #
#    Updated: 2025/04/09 16:18:40 by mcalciat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) -g
RM = rm -f

SRC_DIR = sources
INC_DIR = includes
LIB_DIR = libft

SRC_FILES = $(SRC_DIR)/minishell.c \
	$(SRC_DIR)/builtins/builtin_cd.c \
	$(SRC_DIR)/builtins/builtin_echo.c \
	$(SRC_DIR)/builtins/builtin_env.c \
	$(SRC_DIR)/builtins/builtin_exit.c \
	$(SRC_DIR)/builtins/builtin_export.c \
	$(SRC_DIR)/builtins/builtin_export2.c \
	$(SRC_DIR)/builtins/builtin_pwd.c \
	$(SRC_DIR)/builtins/builtin_unset.c \
	$(SRC_DIR)/env_utils/env_utils1.c \
	$(SRC_DIR)/env_utils/env_utils2.c \
	$(SRC_DIR)/env_utils/free_env_list.c \
	$(SRC_DIR)/executor/exec_builtins.c \
	$(SRC_DIR)/executor/exec_commands.c \
	$(SRC_DIR)/executor/exec_pipes.c \
	$(SRC_DIR)/executor/exec_redirections.c \
	$(SRC_DIR)/parser/lexer.c \
	$(SRC_DIR)/parser/expander.c \
	$(SRC_DIR)/parser/parser.c \
	$(SRC_DIR)/parser/parser2.c \
	$(SRC_DIR)/signals/signal_handler.c \
	$(SRC_DIR)/utils/quit_program.c \
	$(SRC_DIR)/utils/utils_cleaner.c \
	$(SRC_DIR)/utils/utils_envpath.c \
	$(SRC_DIR)/utils/utils_executor.c \
	$(SRC_DIR)/utils/utils_expander.c \
	$(SRC_DIR)/utils/utils_input.c \
	$(SRC_DIR)/utils/utils_parser.c

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
