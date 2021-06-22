#ifndef LOTCRAF_H
# define LOTCRAF_H

#include "./srcs/Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
# define ERROR_ARG "Do you wanna mean [Julia] or [Mandelbrot] ?"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;

}				t_data;


#define WIDTH 1080
#define HEIGHT 1080


#endif