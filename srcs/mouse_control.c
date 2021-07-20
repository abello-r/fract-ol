/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:00:43 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/20 21:04:25 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int ft_mouse(int key, t_g *g)
{
	if (key == 5 || key == 1)
		ft_in_win(g);
	else if (key == 4 || key == 2)
		ft_leave_win(g);
	return (0);
}

int	ft_in_win(t_g *g)
{
	g->aliuj.zoom *= pow(1.001, (WIDTH / 10));
	g->mb.zoom *= pow(1.001, (WIDTH / 10));
	return (0);
}

int ft_leave_win(t_g *g)
{
	g->aliuj.zoom /= pow(1.001, (WIDTH / 10));
	g->mb.zoom /= pow(1.001, (WIDTH / 10));
	return (0);
}
