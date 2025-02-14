# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 13:14:03 by mcalciat          #+#    #+#              #
#    Updated: 2025/02/12 15:17:18 by mcalciat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- FLAGS --------------------------------#
CC = cc 
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) -g
AR = ar
ARFLAGS = rcs
RM = rm -f

#---------------------- DIRECTORIES ----------------------#
SRC_DIR = src
INC_DIR = inc
LIB_DIR = libft_printf

#------------- SOURCE FILES -------------------------------#
SRC = $(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/operations/push.c \
	$(SRC_DIR)/operations/reverse_rotate.c \
	$(SRC_DIR)/operations/rotate.c \
	$(SRC_DIR)/operations/swap.c \
	$(SRC_DIR)/sorting/normalize.c \
	$(SRC_DIR)/sorting/push_outils.c \
	$(SRC_DIR)/sorting/sort_bigger_stacks.c \
	$(SRC_DIR)/sorting/sort_three.c \
	$(SRC_DIR)/sorting/sorting_outils.c \
	$(SRC_DIR)/stack_handling/create_stack.c \
	$(SRC_DIR)/stack_handling/ft_atol.c \
	$(SRC_DIR)/stack_handling/parse_num.c \
	$(SRC_DIR)/stack_handling/print_stack.c \
	$(SRC_DIR)/stack_handling/split_num.c \
	$(SRC_DIR)/stack_handling/stack_outils.c \
	$(SRC_DIR)/stack_handling/validate_input.c \
	
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

LIB_FILE = $(LIB_DIR)/libft_printf.a

#-------------------- NAME --------------------------------#
NAME = push_swap

#------------------RULES ----------------------------------#
all: $(LIB_FILE) $(NAME)

$(LIB_FILE):
	make all -C $(LIB_DIR)

%.o: %.c $(LIB_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -lft_printf -o $(NAME)

bonus: all $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all bonus

.PHONY: all clean fclean re bonus
