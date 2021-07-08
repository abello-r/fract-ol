/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:31:16 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/06 13:18:54 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

void	ft_mandelbrot(t_g *g)
{
	int	y;
	int	x;
	int	i;
	int	color;

	i = 0;
	y = 0;
	x = 0;

	ft_init_structs(g);
	color = ft_rgb(0,235,0);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			g->mb.pr = 1.5 * (x - WIDTH / 2) / (0.5 * g->mb.zoom * WIDTH) + g->mb.mov_x;
			g->mb.pi = (y - HEIGHT / 2) / (0.5 * g->mb.zoom * HEIGHT) + g->mb.mov_y;
			g->mb.newre = 0;
			g->mb.newin = 0;
			g->mb.oldre = 0;
			g->mb.oldim = 0;
			i = 0;
			while (i < g->mb.max_itr)
			{
				g->mb.oldre = g->mb.newre;
				g->mb.oldim = g->mb.newin;
				g->mb.newre = g->mb.oldre * g->mb.oldre - g->mb.oldim * g->mb.oldim + g->mb.pr;
				g->mb.newin = 2 * g->mb.oldre * g->mb.oldim + g->mb.pi;
				if ((g->mb.newre * g->mb.newre + g->mb.newin * g->mb.newin) > 4)
					break ;
				my_mlx_pixel_put(g, x, y, color << i);
				i++;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->data.mlx, g->data.win, g->data.img, 0, 0);
}
