# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 11:54:03 by jolivare          #+#    #+#              #
#    Updated: 2025/03/21 12:17:30 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/Bureaucrat.cpp src/AForm.cpp src/PresidentialPardonForm.cpp \
      src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp main.cpp
OBJ_DIR = obj
OBJECTS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CC = c++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = Bureaucrat

all: $(NAME)

# Asegurar que el directorio y sus subdirectorios existen
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
