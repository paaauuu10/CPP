# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 11:40:30 by pbotargu          #+#    #+#              #
#    Updated: 2024/11/13 16:31:29 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
MAGENTA = \033[1;35m
BLUE = \033[38;5;75m
ORIGINAL = \033[0m

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
RM = rm -rf

#DIRECTORIES
D_OBJ = obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.d))

all: dir $(NAME)

-include $(DEP)

dir:
		@mkdir -p $(D_OBJ)

# Construcción de los objetos
$(D_OBJ)/%.o: %.cpp Makefile
		@$(CPP) $(FLAGS) -MMD -MP -c $< -o $@
		@echo "$(GREEN)[OK]             $(BLUE).o Correctly done!"

# Creación del ejecutable
$(NAME): $(OBJ)
		@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "$(GREEN)[OK]             $(BLUE)Project $(NAME) successfully compiled!!"

clean:
		@$(RM) $(D_OBJ)
		@echo "$(GREEN)[OK]             $(RED)Cleaned successfully!"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(GREEN)[OK]             $(RED)All removed successfully!"

re: fclean all

.PHONY: all clean fclean re