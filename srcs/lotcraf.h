#ifndef LOTCRAF_H
# define LOTCRAF_H

#include "./Libft/libft.h"
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

# define ERROR_ARG "Do you mean [Julia] or [Mandelbrot] ?"

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr; // Data minilibx

	int			bits_per_pixel;
	int			line_lenght;
	int			endian;

	double		a;
	double		b; // Complex numbs
	double		c;

	double		x;
	double		y; // Coord
	double		z;

}				t_data;

typedef struct	aliuj
{
	double		cre;
	double		cim;
	double		newre;
	double		newin;
	double		oldre;
	double		oldim;
	double		zoom;
	double		mov_x;
	double		mov_y;
	int			max_itr;

}				t_aliuj;

typedef	struct	g
{
	t_aliuj aliuj;
	t_data	data;

}				t_g;

void	ft_init_structs(t_g *g);
int		ft_exit(t_g *g);
void	ft_julia(t_g *g);
void	ft_mandelbrot(t_g *g);
void	my_mlx_pixel_put(t_g *g, int x, int y, int color);
int		ft_rgb(int r, int g, int b);

#endif