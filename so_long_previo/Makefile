#-------------------- NAME --------------------------------#
NAME = so_long

# ----------------- FLAGS --------------------------------#
CC = cc 
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)/inc
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
RM = rm -f

AR = ar
ARFLAGS = rcs

#---------------------- DIRECTORIES ----------------------#
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = libft_printf
MLX_DIR = minilibx-linux

#------------- SOURCE FILES -------------------------------#
SRCS = $(SRC_DIR)/so_long.c \
	$(SRC_DIR)/enemies.c \
	$(SRC_DIR)/enemies_move.c \
	$(SRC_DIR)/map_creation1.c \
	$(SRC_DIR)/map_creation2.c \
	$(SRC_DIR)/map_creation3.c \
	$(SRC_DIR)/map_validation1.c \
	$(SRC_DIR)/map_validation2.c \
	$(SRC_DIR)/free_outils.c \
	$(SRC_DIR)/mlx_load_render.c \
	$(SRC_DIR)/moves.c \
	$(SRC_DIR)/render_elements.c 

#------------- OBJECT FILES -------------------------------#
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \

#------------- DEPENDENCIES FILES --------------------------#
LIBFT_FILE = $(LIBFT_DIR)/libft_printf.a

#------------------RULES ----------------------------------#

# Default rule
all: $(OBJ_DIR) $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the final executable
$(NAME): $(LIBFT_FILE) $(OBJS)
	$(CC) $(OBJS) $(LIBFT_FILE) $(MLX_FLAGS) -o $(NAME)

# Compile libft if not already compiled
$(LIBFT_FILE):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

# Full clean (removes compiled binary)
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

# Recompile everything
re: fclean all

# Bonus rule (if needed)
bonus: all

# PHONY targets (avoid conflicts with files of the same name)
.PHONY: all clean fclean re bonus
