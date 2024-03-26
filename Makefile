##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## abc
##

SRC = $(shell find src/ -type f -name "*.c")

SRC_NO_MAIN = $(shell find src/ -type f -name "*.c" ! -name "main.c")

SRC_TESTS = $(shell find tests/ -type f -name "*.c")

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
	rm -f unit_tests
	rm -f *.gcdo
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)

tests_run: all
	gcc -o unit_tests $(SRC_NO_MAIN) $(SRC_TESTS) \
		--coverage -lcriterion $(CFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

re: clean fclean all
