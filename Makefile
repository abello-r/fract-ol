NAME= ./srcs/lotcraf.a

SRCS=	./srcs/fractol.c \
		./srcs/julia.c \
		./srcs/mandelbrot.c \
		./srcs/utils.c \
		./srcs/key_control.c \
		./srcs/color_control.c \
		./srcs/mouse_control.c

OBJS= $(SRCS:.c=.o)

CC= gcc

CFLAGS= -Wall -Werror -Wextra

RM= rm -rf

$(NAME): $(OBJS)
	@clear
	@echo "\n\033[32m"Compiling... [❄]"\n"
	@make -sC ./srcs/Libft/
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) libft.a -lmlx -framework OpenGL -framework AppKit -o fractol
	@mv libft.a ./srcs

all: $(NAME)

re:	fclean all

clean:
	@$(RM) fractol $(OBJS)
	@make -sC ./srcs/Libft/ clean
	@clear
	@echo "\n\033[32m"Junk files deleted ✅"\n"

fclean:
	@$(RM) fractol $(NAME) $(OBJS) ; $(RM) ./srcs/lotcraf.a ./srcs/libft.a
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\n\033[32m"Junk files deleted ✅"\n"

.PHONY: fclean clean all re