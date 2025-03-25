# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 11:12:16 by mcalciat          #+#    #+#              #
#    Updated: 2025/03/25 14:10:54 by mcalciat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) -g
AR = ar
ARFLAGS = rcs
RM = rm -f

#---------------------- DIRECTORIES ----------------------#
SRC_DIR = sources
INC_DIR = includes
LIB_DIR = libft

#------------- SOURCE FILES -------------------------------#
SRC_CLIENT = $(SRC_DIR)/builtin_echo.c

OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

LIB_FILE = $(LIB_DIR)/libft.a

#-------------------- NAME --------------------------------#
NAME = tester

#------------------RULES ----------------------------------#
all: $(LIB_FILE) $(NAME) $(NAMESV)

$(LIB_FILE):
	make all -C $(LIB_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(LIB_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB_FILE) -o $(NAME)

clean:
	$(RM) $(OBJ_CLIENT)
	make clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all bonus

.PHONY: all clean fclean re bonus
