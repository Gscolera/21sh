NAME = 21sh
SRC = main.c reader/*.c helpers/*.c lexer/*.c executer/*.c env/*.c builtin/*.c
OBJ = $(SRC:.c = .o)
LIBFT = -L libft -lft
TERMCAP = -ltermcap
INC = -I includes -I libft/includes
FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	gcc  $(OBJ) $(INC) $(LIBFT) $(TERMCAP) -o $(NAME)

all: $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
