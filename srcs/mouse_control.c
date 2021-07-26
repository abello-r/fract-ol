/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:00:43 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/26 13:57:52 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	ft_mouse(int key, int x, int y, t_g *g)
{
	x = 0;
	y = 0;
	if (key == SCROLL_UP)
	{
		g->aliuj.zoom += 0.02;
		g->mb.zoom += 0.02;
	}
	else if (key == SCROLL_DOWN)
	{
		g->aliuj.zoom -= 0.02;
		g->mb.zoom -= 0.02;
	}
	return (0);
}
