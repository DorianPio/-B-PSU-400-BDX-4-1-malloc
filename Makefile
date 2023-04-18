##
##EPITECHPROJECT,2021
##B-CPP-300-BDX-3-1-CPPrush1-dorian.pio
##Filedescription:
##Makefile
##

CC						=	gcc

SRC						=	malloc.c	\
							free.c		\
							calloc.c	\
							realloc.c	\
							realloc2.c	\
							utils.c

override CPPFLAGS		=	-I./include/

override CFLAGS			= 	-fPIC

LDFLAGS					=	-shared

OBJ						=	$(SRC:.c=.o)

NAME					=	libmy_malloc.so

RM_F					=	rm

BBLUE					=	\033[1;34m
GREEN					=	\033[32m
RED						=	\033[31m
RESET					=	\033[0m

all:					$(NAME)

$(NAME):				$(OBJ)
						$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
						$(RM) $(OBJ)

fclean:						clean
						$(RM) $(NAME)
						echo "$(RED)Clean$(RESET) all the project"

re:						fclean all

test_run:

.PHONY:					all $(NAME) clean fclean re