# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 16:56:33 by jolivare          #+#    #+#              #
#    Updated: 2024/11/24 16:59:04 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp RPN.cpp
OBJ_DIR = obj
OBJECTS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CC = g++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

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