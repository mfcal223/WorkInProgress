# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 13:04:22 by mcalciat          #+#    #+#              #
#    Updated: 2025/03/17 15:15:58 by mcalciat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------- NAME --------------------------------#
NAME = philo

# ----------------- FLAGS --------------------------------#
CC = cc 
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f

# AR = ar
# ARFLAGS = rcs

#------------- SOURCE FILES -------------------------------#
SRCS = main.c checks.c cleaning.c initialization.c \
	monitors.c routine.c routine2.c tools.c  validation.c

#------------- OBJECT FILES -------------------------------#
OBJS = $(addprefix obj/, $(SRCS:.c=.o))

#------------- DEPENDENCIES FILES --------------------------#
# there are non authorized

#------------------RULES ----------------------------------#

# Default rule
all: $(NAME)

# Compilation
$(NAME): obj_dir $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Ensure obj directory exists
obj_dir:
	mkdir -p obj

# Object file compilation
obj/%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)

# Full clean (removes compiled binary)
fclean: clean
	$(RM) $(NAME)

# Recompile everything
re: fclean all

# Bonus rule (if needed)
bonus: all

# PHONY targets (avoid conflicts with files of the same name)
.PHONY: all clean fclean re bonus
