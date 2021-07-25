/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:00:43 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/25 15:03:47 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	ft_mouse(int key, int x, int y, t_g *g)
{
	x = 0;
	y = 0;
	if (key == SCROLL_UP)
	{
		g->aliuj.zoom *= pow(1.001, (WIDTH / 10));
		g->mb.zoom *= pow(1.001, (WIDTH / 10));
	}
	else if (key == SCROLL_DOWN)
	{
		g->aliuj.zoom /= pow(1.001, (WIDTH / 10));
		g->mb.zoom /= pow(1.001, (WIDTH / 10));
	}
	return (0);
}
