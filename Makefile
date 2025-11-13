

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_print_dIu.c ft_print_p.c ft_print_s.c ft_print_x.c ft_print_X.c ft_printf.c  

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ)
%.o : %.c  
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY :
