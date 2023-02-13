# Makefile

NAME = pipex
NAME_BONUS = pipex_bonus
LIBFT = libft/
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g -I
FSANI = -fsanitize=address
VAL = valgrind --leak-check=full
SRCS =  pipex.c \
		cmd_path.c \
		set_cmd.c \
		ft_errors.c \
		ft_close.c \
		init_variables.c \
		ft_open.c
SRCS_BONUS = bonus/pipex_bonus.c \
			 bonus/cmd_path_bonus.c \
			 bonus/set_cmd_bonus.c \
			 bonus/ft_errors_bonus.c \
			 bonus/ft_process_bonus.c \
			 bonus/heredoc_bonus.c \
			 bonus/ft_open_bonus.c
OBJECT_FILES = $(SRCS:.c=.o)
OBJECT_BONUS = $(SRCS_BONUS:.c=.o)
HEADER = ./
HEADER_BONUS = bonus/

all: $(NAME) 
.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECT_FILES)
	@echo "$(YELLOW)\n<<<<< libft compiling ... >>>>>\n$(DEFAULT)"
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	@echo "$(YELLOW)\n<<<<< Creating pipex exec file ! ... >>>>>$(DEFAULT)"
	$(CC) $(CFLAGS) -c -o $(NAME) $(SRCS) libft/libft.a 
	@echo "$(GREEN)\n<<<<< pipex created ! ... >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
clean: 
	@echo "$(RED)\n<<<<< deleting pipex obj. files ! ... >>>>>$(DEFAULT)"
	rm -rf $(OBJECT_FILES) $(OBJECT_BONUS)
	@echo "$(GREEN)<<<<< clean from pipex done ! >>>>>\n$(DEFAULT)"
	$(MAKE) clean -C $(LIBFT)
#------------------------------------------------------------------------------
fclean: clean
	@echo "$(RED)<<<<< deleting pipex exec ! >>>>>\n$(DEFAULT)"
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT)
	@echo "$(GREEN)<<<<< fclean from pipex done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
re: fclean all
	@echo "$(GREEN)\n<<<<< pipex make re done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
bonus: $(NAME_BONUS) $(OBJECT_BONUS)

$(NAME_BONUS): $(OBJECT_BONUS)
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME_BONUS)
	@echo "$(YELLOW)\n<<<<< Creating pipex_bonus exec file ! ... >>>>>\n$(DEFAULT)"
	$(CC) $(CFLAGS) -c -o $(NAME_BONUS) $(SRCS_BONUS) libft/libft.a
	@echo "$(GREEN)\n<<<<< pipex_bonus created ! ... >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
