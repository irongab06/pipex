NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = src/pipex.c utile/ft_utile_init_struct.c utile/ft_utile_path.c\
utile/ft_utile_pipe.c utile/ft_utile_free_malloc.c utile/ft_utile_pid.c\
utile/ft_utile_error.c src/fork.c utile/ft_utile_dup.c\
utile/ft_utile_open_close_file.c utile/ft_utile_close.c\
utile/ft_utile_check_cmd.c src/execve.c src/here_doc.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ = $(SRC:.c=.o)
FLAG_FILE = .mode_flag
TOTAL_FILES := $(words $(SRC))

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m  # No Color


all: check_normal $(LIBFT) $(NAME)

bonus: CFLAGS += -DBONUS=1
bonus: check_bonus $(LIBFT) $(NAME)

check_normal:
	@if [ -f $(FLAG_FILE) ] && grep -q "bonus" $(FLAG_FILE); then \
		echo "Switching to normal mode, recompiling..."; \
		$(MAKE) fclean --silent; \
	fi
	@if [ -f $(FLAG_FILE) ] && grep -q "normal" $(FLAG_FILE); then \
		echo "Already compiled in normal mode."; \
		exit 0; \
	fi
	@echo "normal" > $(FLAG_FILE)

check_bonus:
	@if [ -f $(FLAG_FILE) ] && grep -q "normal" $(FLAG_FILE); then \
		echo "Switching to bonus mode, recompiling..."; \
		$(MAKE) fclean --silent; \
	fi
	@if [ -f $(FLAG_FILE) ] && grep -q "bonus" $(FLAG_FILE); then \
		echo "Already compiled in bonus mode."; \
		exit 0; \
	fi
	@echo "bonus" > $(FLAG_FILE)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
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
	@rm -f $(NAME) $(FLAG_FILE)
	@make -C $(LIBFT_DIR) fclean --silent

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
