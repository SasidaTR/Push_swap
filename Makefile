NAME = push_swap

SRC = $(wildcard src/*.c) $(wildcard libft/*.c) $(wildcard utils/*.c)
OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ := $(OBJ:libft/%.c=$(OBJ_DIR)/%.o)
OBJ := $(OBJ:utils/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: utils/%.c | $(OBJ_DIR) 
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
