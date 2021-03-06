/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lotcraf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:18:09 by abello-r          #+#    #+#             */
/*   Updated: 2021/08/03 12:18:23 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOTCRAF_H
# define LOTCRAF_H

# include "./Libft/libft.h"
# include "macrox.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH 1080
# define HEIGHT 1080

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
# define ERROR_ARG "Do you mean [Julia] or [Mandelbrot] ?"
# define ERROR_PARAM "Color params : [red] [green] [blue] [white] [gold]"

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			color;
	int			w;
	int			s;
	int			d;
	int			a;
	int			pepito;

}				t_data;

typedef struct s_aliuj
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

typedef struct s_mb
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
	double		pr;
	double		pi;
	int			max_itr;
}				t_mb;

typedef struct s_g
{
	t_aliuj	aliuj;
	t_mb	mb;
	t_data	data;

}				t_g;

void	my_mlx_pixel_put(t_g *g, int x, int y, int color);
void	ft_init_structs(t_g *g);
int		ft_exit(t_g *g);
int		key_press(int keycode, t_g *g);
int		key_release(int keycode, t_g *g);
int		key_move(t_g *g);
int		ft_julia(t_g *g);
int		ft_mandelbrot(t_g *g);
int		ft_rgb(int r, int g, int b);
void	ft_param_color(t_g *g, int argc, char **argv);
void	ft_color_option(t_g *g, char *param);
int		ft_mouse(int key, int x, int y, t_g *g);
int		ft_parser_arg(int argc, char **argv, t_g *g);

#endif