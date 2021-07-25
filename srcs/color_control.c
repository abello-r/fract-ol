/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:02:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/25 15:41:28 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

void	ft_param_color(t_g *g, int argc, char **argv)
{
	if (argc == 2)
		g->data.color = ft_rgb(128, 0, 128);
	else if (ft_strcmp(argv[2], "red") && ft_strcmp(argv[2], "blue")
		&& ft_strcmp(argv[2], "green") && ft_strcmp(argv[2], "gold")
		&& ft_strcmp(argv[2], "white"))
	{
		write(1, RED ERROR_PARAM"\n", 57);
		exit (1);
	}
	if (argc == 3)
		ft_color_option(g, argv[2]);
}

void	ft_color_option(t_g *g, char *param)
{
	if (ft_strcmp(param, "red") == 0)
		g->data.color = ft_rgb(255, 0, 0);
	else if (ft_strcmp(param, "green") == 0)
		g->data.color = ft_rgb(0, 255, 0);
	else if (ft_strcmp(param, "blue") == 0)
		g->data.color = ft_rgb(0, 0, 255);
	else if (ft_strcmp(param, "white") == 0)
		g->data.color = ft_rgb(255, 255, 255);
	else if (ft_strcmp(param, "gold") == 0)
		g->data.color = ft_rgb(255, 215, 0);
}

int	ft_rgb(int r, int g, int b)
{
	int	rgb;

	if (r > 255 || g > 255 || b > 255)
		write(1, "El RGB máximo es de 255\n", 25);
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
