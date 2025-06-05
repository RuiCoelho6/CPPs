# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 12:05:01 by rpires-c          #+#    #+#              #
#    Updated: 2025/05/28 15:46:18 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Now_were_talking

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Fixed.cpp

OBJDIR = Objs
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@ $(CC) -c $(FLAGS) -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

all: $(NAME)

clean:
	@$(RM) -r $(NAME)
	@$(RM) -r $(OBJDIR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re