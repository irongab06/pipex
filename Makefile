NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = src/pipex.c utile/ft_utile_init_struct.c utile/ft_utile_path.c\
utile/ft_utile_pipe.c utile/ft_utile_free_malloc.c utile/ft_utile_pid.c\
utile/ft_utile_error.c src/fork.c utile/ft_utile_dup.c\
utile/ft_utile_open_close_file.c utile/ft_utile_close.c\
utile/ft_utile_check_cmd.c src/execve.c src/here_doc.c
SRC_BONUS = src/pipex_bonus.c utile/ft_utile_init_struct.c utile/ft_utile_path.c\
utile/ft_utile_pipe.c utile/ft_utile_free_malloc.c utile/ft_utile_pid.c\
utile/ft_utile_error.c src/fork.c utile/ft_utile_dup.c\
utile/ft_utile_open_close_file.c utile/ft_utile_close.c\
utile/ft_utile_check_cmd.c src/execve.c src/here_doc.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ = $(SRC:.c=.o)
TOTAL_FILES := $(words $(SRC))
COMPILED_FILES = 0

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m  # No Color

all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(BONUS_NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)

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
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFT_DIR) clean --silent

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean --silent

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus