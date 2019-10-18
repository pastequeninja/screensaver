##
## EPITECH PROJECT, 2018
## makefile
## File description:
## ScreenSaver Makefile Mai Ly Lehoux
##

CC		=	gcc

GRAPH_FLAG	=	-lcsfml-window -lcsfml-graphics -lcsfml-system

LDFLAGS		=	-L./lib/screen_saver
LDLIBS		=	-lmy

LIBS		=	-lm

CFLAGS		=	-I./include -Wall -Wextra -Wshadow -Werror

RM		=	rm -f

SRCS		=	src/main.c \
			src/error_usage/errors.c \
			src/error_usage/print_usage.c \
			src/scenes/alpha.c \
			src/create_buff.c \
			src/scenes/beta.c \
			src/scenes/put_pixels.c \
			src/scenes/dark_heads.c \
			src/redirect_scenes.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	my_screensaver

all		:
		$(MAKE) -C./lib/screen_saver re
		$(MAKE) $(NAME) --no-print-directory

$(NAME)		:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(GRAPH_FLAG) $(LDFLAGS) $(LDLIBS) $(LIBS)

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)
		$(MAKE) -s -C./lib/screen_saver fclean

re		:
		$(MAKE) fclean --no-print-directory
		$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
