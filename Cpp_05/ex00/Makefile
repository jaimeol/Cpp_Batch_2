# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 11:54:03 by jolivare          #+#    #+#              #
#    Updated: 2024/12/02 15:05:43 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Bureaucrat.cpp main.cpp
OBJ_DIR = obj
OBJECTS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CC = c++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re