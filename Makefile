##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## abc
##

SRC = $(shell find src/ -type f -name "*.c")

OBJ = $(SRC:src/%.c=obj/%.o)

NAME = mysh

CFLAGS = -Wall -Wextra -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

tests_run:
	cat "test"

re: clean fclean all
