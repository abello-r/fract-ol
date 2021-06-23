NAME= lotcraf.a

SRCS=	./srcs/fractol.c \
		./srcs/julia.c \
		./srcs/mandelbrot.c \
		./srcs/utils_keys.c

OBJS= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@clear
	@echo "\n\033[32m"Compiling... [⏳]"\n"
	@make -sC ./srcs/Libft/
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@mv libft.a ./srcs ; mv lotcraf.a ./srcs
	@gcc -Wall -Werror -Wextra $(SRCS) libft.a -lmlx -framework OpenGL -framework AppKit
	@mv ./srcs/fractol . ; mv ./srcs/julia .

all: $(NAME)

re:	fclean all

clean:
	@rm -f $(OBJ)
	@make -sC ./srcs/Libft/ clean
	@clear
	@echo "\n\033[32m"Junk files deleted [✅]"\n"

fclean:
	@rm -f $(NAME) $(OBJ) *.a
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\n\033[32m"Junk files deleted [✅]"\n"

PHONY: fclean clean all