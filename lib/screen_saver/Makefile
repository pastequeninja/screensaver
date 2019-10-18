##
## EPITECH PROJECT, 2018
## Makefile - BSQ
## File description:
## Mai Ly Lehoux
##

CC	=	gcc

SRCS	=	my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_strlen.c

OBJS	=	$(SRCS:.c=.o)

NAME 	=	libmy.a

RM	=	rm -f

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

all:	$(NAME)

re:	fclean all
