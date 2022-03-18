NAME = fractol

NAMEB = fractol_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES = /usr/local/include

SRC = fractol.c fractol_utils.c ft_strcmp.c zoom.c mandelbrot.c\
	  julia.c ft_putendl.c messages.c colors.c

SRCB = fractol_bonus.c fractol_utils.c ft_putendl.c ft_strcmp.c mandelbrot.c julia.c\
	   burning_ship_bonus.c moves_bonus.c\
	   zoom_bonus.c messages_bonus.c colors.c

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -lmlx -framework OpenGL -framework appKit -o $(NAME)

	
bonus: $(SRCB)
	$(CC) $(FLAGS) $(SRCB) -lmlx -framework OpenGL -framework appKit -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
