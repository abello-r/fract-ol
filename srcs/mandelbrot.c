/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:31:16 by abello-r          #+#    #+#             */
/*   Updated: 2021/08/04 16:11:30 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

void	ft_mandel_help(t_g *g, int x, int y)
{
	g->mb.pr = 1.5 * (x - WIDTH / 1.5)
		/ (0.5 * g->mb.zoom * WIDTH) + g->mb.mov_x;
	g->mb.pi = (y - HEIGHT / 2)
		/ (0.4 * g->mb.zoom * HEIGHT) + g->mb.mov_y;
	g->mb.newre = 0;
	g->mb.newin = 0;
	g->mb.oldre = 0;
	g->mb.oldim = 0;
}

void	ft_mandel_ecuation(t_g *g)
{
	g->mb.oldre = g->mb.newre;
	g->mb.oldim = g->mb.newin;
	g->mb.newre = g->mb.oldre * g->mb.oldre
		- g->mb.oldim * g->mb.oldim + g->mb.pr;
	g->mb.newin = 2 * g->mb.oldre * g->mb.oldim + g->mb.pi;
}

int	ft_mandelbrot(t_g *g)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	mlx_do_sync(g->data.mlx);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_mandel_help(g, x, y);
			i = -1;
			while (++i < g->mb.max_itr)
			{
				ft_mandel_ecuation(g);
				if ((g->mb.newre * g->mb.newre + g->mb.newin * g->mb.newin) > 4)
					break ;
				my_mlx_pixel_put(g, x, y, g->data.color << i);
			}
		}
	}
	mlx_put_image_to_window(g->data.mlx, g->data.win, g->data.img, 0, 0);
	key_move(g);
	return (0);
}
