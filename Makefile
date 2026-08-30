CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I.
DEPS = wom.h
SOURCES = main.c ft_anim.c ft_atk.c ft_enemy_atk.c ft_exp.c ft_itoa.c ft_lvl_up.c ft_nom.c ft_put_str.c ft_show_exp.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = a.out

all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
