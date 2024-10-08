NAME = PhoneBook

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
MAGENTA = \033[1;35m
BLUE = \033[38;5;75m
ORIGINAL = \033[0m

CPP = c++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp
RM = rm -rf

#DIRECTORIES
D_OBJ = obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.d))

all: dir $(NAME)

-include $(DEP) #el signo '-' evita problemas si no existen dependencias

dir:
	@mkdir -p $(D_OBJ)

#construimos los objetos en el directorio $(D_OBJ)/
#-MMD -c se usa para generar archivos de dependencia y compilar. El $< se refiera al archivo fuente y $@ al objeto
$(D_OBJ)/%.o: %.cpp Makefile
		@$(CPP) $(FLAGS) -MMD -MP -c $< -o $@
		@echo "$(GREEN)[OK]		$(BLUE).o Correctly done!"

#Construimos el archivo ejecutable a partir de los objetos
$(NAME): $(OBJ) Makefile
		@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "$(GREEN)[OK]		$(BLUE)Project $(NAME) successfully compiled!!"

clean:
		@$(RM) $(D_OBJ)
		@echo "$(GREEN)[OK]		$(RED)Cleaned successfully!"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(GREEN)[OK]		$(RED)All removed successfully!"

re: fclean all

.PHONY: all clean fclean re