# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 15:10:35 by rpires-c          #+#    #+#              #
#    Updated: 2025/07/30 13:55:03 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Abstract

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJDIR = Objs
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

# Detect OS for cross-platform compatibility
ifeq ($(OS),Windows_NT)
	RM = del /Q
	RMDIR = rmdir /S /Q
	MKDIR = if not exist $(OBJDIR) mkdir $(OBJDIR)
	SHELL_MKDIR = if not exist $(OBJDIR) mkdir $(OBJDIR)
else
	RM = rm -f
	RMDIR = rm -rf
	MKDIR = mkdir -p $(OBJDIR)
	SHELL_MKDIR = mkdir -p $(OBJDIR)
endif

$(shell $(SHELL_MKDIR))

$(OBJDIR)/%.o: %.cpp
	@$(MKDIR)
	@$(CC) -c $(FLAGS) -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

all: $(NAME)

clean:
ifeq ($(OS),Windows_NT)
	@if exist $(OBJDIR) $(RMDIR) $(OBJDIR)
else
	@$(RM) $(NAME)
	@$(RMDIR) $(OBJDIR)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	@if exist $(NAME).exe $(RM) $(NAME).exe
else
	@$(RM) $(NAME)
endif

re: fclean all

.PHONY: all clean fclean re