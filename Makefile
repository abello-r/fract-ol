NAME= lotcraf.a
SRCS= fractol.c julia.c mandelbrot.c 
OBJS= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@make -sC ./srcs/Libft/
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\033[32m"Archivos compilados correctamente ✅"\n"
	gcc -Wall -Werror -Wextra $(SRCS) libft.a -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

re:	fclean all

clean:
	@rm -f $(NAME) $(OBJ)
	@make -sC ./srcs/Libft/ clean
	@clear
	@echo "\n\033[32m"Todo depurado correctamente ✅"\n"
	@ls

fclean:
	@rm -f $(NAME) $(OBJ) *.a
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\n\033[32m"Todo depurado correctamente ✅"\n"
	@ls

PHONY: fclean clean all