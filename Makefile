# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 19:29:57 by miguelmo          #+#    #+#              #
#    Updated: 2025/09/06 12:03:50 by miguelmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c check_args.c normalize.c tinyshort.c calculate_cost.c move_cheapest.c \
	swap.c rotate.c push.c reverse_rotate.c \
	utils.c utils2.c utils3.c utils4.c moves.c\
	create_utils.c big_sort.c more_costs.c\

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

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
	@$(RM) $(OBJ)
fclean: clean
		@echo "$(YELLOW)Removing executable...$(RESET)"
		@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re