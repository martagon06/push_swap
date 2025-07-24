# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 19:29:57 by miguelmo          #+#    #+#              #
#    Updated: 2025/07/24 20:15:53 by miguelmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


SOURCES = \ 
		main.c check_args.c / 

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f 
MKDIR = mkdir -p


GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m


all: $(NAME)

$(NAME): $(OBJECTS)
		@echo "$(GREEN)Linking $@$(RESET)"
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "$(GREEN)Executable $(NAME) created!$(RESET)"

$(OBJECTS)%.o: $(SOURCES)%.c
		@$(MKDIR) $(OBJ_DIR)
		@echo "$(YELLOW)Compiling $<$(RESET)"
		@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean: 
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
fclean: clean
		@echo "$(YELLOW)Removing executable...$(RESET)"
		@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re