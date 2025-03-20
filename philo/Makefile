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
SRCS = cleaning.c initialization.c main.c monitor_death.c \
	monitor_meal.c routine.c routine2.c simulation.c tools.c \
	validation.c

#------------- OBJECT FILES -------------------------------#
OBJS = $(addprefix obj/, $(SRCS:.c=.o))

#------------- DEPENDENCIES FILES --------------------------#
# there are non authorized

#------------------RULES ----------------------------------#

# Default rule
all: $(NAME)

# Object file compilation (Fixed to prevent relinking)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Ensure obj directory exists (Order-only dependency prevents relinking)
obj_dir:
	@mkdir -p obj 
# `@` prevents printing "mkdir -p obj" on every make

# Object file compilation
obj/%.o: %.c philo.h | obj_dir
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
