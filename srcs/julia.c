/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:31:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/26 13:44:50 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	ft_julia_help(t_g *g, int x, int y)
{
	g->aliuj.newre = 1.5 * (x - WIDTH / 2)
		/ (0.5 * g->aliuj.zoom * WIDTH) + g->aliuj.mov_x;
	g->aliuj.newin = (y - HEIGHT / 2)
		/ (0.5 * g->aliuj.zoom * HEIGHT) + g->aliuj.mov_y;
	return (-1);
}

void	ft_julia_ecuation(t_g *g)
{
	g->aliuj.oldre = g->aliuj.newre;
	g->aliuj.oldim = g->aliuj.newin;
	g->aliuj.newre = g->aliuj.oldre * g->aliuj.oldre
		- g->aliuj.oldim * g->aliuj.oldim + g->aliuj.cre;
	g->aliuj.newin = 2 * g->aliuj.oldre
		* g->aliuj.oldim + g->aliuj.cim;
}

int	ft_julia(t_g *g)
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
			i = ft_julia_help(g, x, y);
			while (++i < g->aliuj.max_itr)
			{
				ft_julia_ecuation(g);
				if ((g->aliuj.newre * g->aliuj.newre
						+ g->aliuj.newin * g->aliuj.newin) > 4)
					break ;
			}
			my_mlx_pixel_put(g, x, y, g->data.color * sqrt(i));
		}
	}
	key_move(g);
	mlx_put_image_to_window(g->data.mlx, g->data.win, g->data.img, 0, 0);
	return (0);
}
