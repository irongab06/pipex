NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = src/pipex.c utile/utile_access.c utile/utile_cpy_cat_malloc.c\
utile/utile_init_variable.c src/ft_fork.c utile/utile_fork.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)
TOTAL_FILES := $(words $(SRC))
COMPILED_FILES = 0

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m  # No Color

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o:
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@PROGRESS=$$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES))); \
	BAR=$$(( $(COMPILED_FILES) * 50 / $(TOTAL_FILES) )); \
	BAR_GRAPH=""; \
	i=0; \
	while [ $$i -lt $$BAR ]; do \
		BAR_GRAPH=$${BAR_GRAPH}/; \
		i=$$((i + 1)); \
	done; \
	i=$$((50 - $$BAR)); \
	while [ $$i -gt 0 ]; do \
		BAR_GRAPH="$${BAR_GRAPH} "; \
		i=$$((i - 1)); \
	done; \
	if [ $$PROGRESS -eq 100 ]; then \
		tput cuu1; tput el; echo "Compiling: [  ${GREEN}$$BAR_GRAPH${NC}] $$PROGRESS%"; \
	else \
		tput cuu1; tput el; echo  "Compiling: [  ${RED}$$BAR_GRAPH${NC}] $$PROGRESS%"; \
	fi

$(LIBFT):
	@make -C $(LIBFT_DIR) --silent

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re bonus