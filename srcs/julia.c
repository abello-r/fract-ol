/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:31:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/01 18:35:09 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

void	ft_julia(t_g *g)
{
	int	y;
	int	x;
	int	i;
	int	color;

	i = 0;
	y = 0;
	x = 0;

	ft_init_structs(g);
	//color = ft_rgb(77,55,70);
	color = ft_rgb(255,255,100);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			g->aliuj.newre = 1.5 * (x - WIDTH / 2) / (0.5 * g->aliuj.zoom * WIDTH) + g->aliuj.mov_x;
			g->aliuj.newin = (y - HEIGHT / 2) / (0.5 * g->aliuj.zoom * HEIGHT) + g->aliuj.mov_y;
			i = 0;
			while (i < g->aliuj.max_itr)
			{
				g->aliuj.oldre = g->aliuj.newre;
				g->aliuj.oldim = g->aliuj.newin;
				g->aliuj.newre = g->aliuj.oldre * g->aliuj.oldre - g->aliuj.oldim * g->aliuj.oldim + g->aliuj.cre;
				g->aliuj.newin = 2 * g->aliuj.oldre * g->aliuj.oldim + g->aliuj.cim;
				if ((g->aliuj.newre * g->aliuj.newre + g->aliuj.newin * g->aliuj.newin) > 4)
					break ;
				my_mlx_pixel_put(g, x, y, color * i);
				i++;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->data.mlx, g->data.win, g->data.img, 0, 0);
}
