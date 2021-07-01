NAME= ./srcs/lotcraf.a

SRCS=	./srcs/fractol.c \
		./srcs/julia.c \
		./srcs/mandelbrot.c \
		./srcs/utils_keys.c

OBJS= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@clear
	@echo "\n\033[32m"Compiling... [❄]"\n"
	@make -sC ./srcs/Libft/
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@gcc -Wall -Werror -Wextra $(SRCS) -fsanitize=address libft.a -lmlx -framework OpenGL -framework AppKit -o fractol
	@mv libft.a ./srcs

all: $(NAME)

re:	fclean all

clean:
	@rm -f fractol $(OBJS)
	@make -sC ./srcs/Libft/ clean
	@clear
	@echo "\n\033[32m"Junk files deleted ✅"\n"

fclean:
	@rm -f fractol $(NAME) $(OBJS) ; rm -rf ./srcs/*.a
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\n\033[32m"Junk files deleted ✅"\n"

PHONY: fclean clean all