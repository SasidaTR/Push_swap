NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard src/*.c) $(wildcard libft/*.c) $(wildcard utils/*.c)
OBJ_DIR = obj
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/src/%.o: src/%.c | $(OBJ_DIR)/src
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libft/%.o: libft/%.c | $(OBJ_DIR)/libft
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/utils/%.o: utils/%.c | $(OBJ_DIR)/utils
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/src $(OBJ_DIR)/libft $(OBJ_DIR)/utils

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
