/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:45:05 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/23 13:10:29 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	key_press(int keycode, t_g *g)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_clear_window(g->data.mlx, g->data.win);
		mlx_destroy_window(g->data.mlx, g->data.win);
		exit(0);
	}
	if (keycode == KEY_W && g->data.w == 0)
		g->data.w = 1;
	if (keycode == KEY_S && g->data.s == 0)
		g->data.s = 1;
	return (0);
}

int	key_release(int keycode, t_g *g)
{
	if (keycode == KEY_W && g->data.w == 1)
		g->data.w = 0;
	if (keycode == KEY_S && g->data.s == 1)
		g->data.s = 0;
	return (0);
}

int	key_move(t_g *g)
{
	if (g->data.w == 1)
	{
		g->aliuj.zoom *= pow(1.001, (WIDTH / 10));
		g->mb.zoom *= pow(1.001, (WIDTH / 10));
	}
	if (g->data.s == 1)
	{
		g->aliuj.zoom /= pow(1.001, (WIDTH / 10));
		g->mb.zoom /= pow(1.001, (WIDTH / 10));
	}
	return (0);
}

int	ft_exit(t_g *g)
{
	mlx_destroy_window(g->data.mlx, g->data.win);
	exit(0);
}
