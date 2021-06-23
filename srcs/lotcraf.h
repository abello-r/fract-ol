#ifndef LOTCRAF_H
# define LOTCRAF_H

#include "./srcs/Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>

#define WIDTH 1080
#define HEIGHT 1080

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

# define ERROR_ARG "Do you wanna mean [Julia] or [Mandelbrot] ?"

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_data;

int		ft_exit(t_data *data);
void	ft_julia(t_data *data);
void	ft_mandelbrot(t_data *data);

#endif