# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 19:29:57 by miguelmo          #+#    #+#              #
#    Updated: 2025/08/13 19:39:31 by miguelmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c check_args.c normalize.c tinyshort.c calculate_cost.c move_cheapest.c \
	swap.c rotate.c push.c reverse_rotate.c \
	utils.c stack_utils.c parse_utils.c error_utils.c \
	push_min_to_b.c is_sorted.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m


all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(GREEN)Linking $@$(RESET)"
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "$(GREEN)Executable $(NAME) created!$(RESET)"

%.o: %.c
		@echo "$(YELLOW)Compiling $<$(RESET)"
		@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
fclean: clean
		@echo "$(YELLOW)Removing executable...$(RESET)"
		@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re