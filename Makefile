CC = gcc

SRC = 	main.c \
		src/player.c\
		src/struct.c \
		src/cursor.c

NAME = space_invaders

CFLAGS = -W -Werror -Wall -Wextra -g

LFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

INCLUDE = -I include/

RM = rm -rf

all:
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LFLAGS) $(INCLUDE) $(LIB)

clean:
	$(RM) src/*.o
	$(RM) ./*.o

fclean: clean
	$(RM) $(NAME)

re: clean all
