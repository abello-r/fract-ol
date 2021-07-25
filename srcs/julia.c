/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:31:20 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/25 16:18:00 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

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
			//Calcular numero real e imaginario.
			g->aliuj.newre = 1.5 * (x - WIDTH / 2) / (0.5 * g->aliuj.zoom * WIDTH) + g->aliuj.mov_x;
			g->aliuj.newin = (y - HEIGHT / 2) / (0.5 * g->aliuj.zoom * HEIGHT) + g->aliuj.mov_y;
			i = 0; // Numero de iteracciones
			while (i < g->aliuj.max_itr) // 300 veces
			{
				g->aliuj.oldre = g->aliuj.newre; // Old real
				g->aliuj.oldim = g->aliuj.newin; // Old ima

				g->aliuj.newre = g->aliuj.oldre * g->aliuj.oldre - g->aliuj.oldim * g->aliuj.oldim + g->aliuj.cre;
				g->aliuj.newin = 2 * g->aliuj.oldre * g->aliuj.oldim + g->aliuj.cim;

				if ((g->aliuj.newre * g->aliuj.newre + g->aliuj.newin * g->aliuj.newin) > 4)
					break ;
				i++;
			}
			my_mlx_pixel_put(g, x, y, g->data.color * sqrt(i)); // ó << i
		}
	}
	key_move(g);
	mlx_put_image_to_window(g->data.mlx, g->data.win, g->data.img, 0, 0);
	return(0);
}
