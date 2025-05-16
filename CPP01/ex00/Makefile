# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 12:04:56 by rpires-c          #+#    #+#              #
#    Updated: 2025/05/16 15:06:46 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = randomChump.cpp newZombie.cpp Zombie.cpp main.cpp

OBJDIR = Objs
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@ $(CC) -c $(FLGS) -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(FLGS) $(OBJS) -o $(NAME)
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
