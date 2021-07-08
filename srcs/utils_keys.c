/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:03:22 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/06 12:58:36 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

void	ft_init_structs(t_g *g)
{
	ft_bzero(&g->aliuj, sizeof(t_aliuj));
	ft_bzero(&g->aliuj, sizeof(t_mb));
	g->aliuj.max_itr = 300;
	g->aliuj.cre = -0.7;
	g->aliuj.cim = 0.27015;
	g->aliuj.zoom = 1;

	g->mb.max_itr = 300;
	g->mb.cre = -0.7;
	g->mb.cim = 0.27015;
	g->mb.zoom = 1;
}

void			my_mlx_pixel_put(t_g *g, int x, int y, int color)
{
	char *dst;

	dst = (char *)g->data.addr + (y * g->data.line_lenght + x * (g->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			ft_rgb(int r, int g, int b)
{
	int rgb;

	if (r > 255 || g > 255 || b > 255)
		write(1, "El RGB máximo es de 255\n", 25);
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
