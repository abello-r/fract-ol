/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:45:05 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/06 12:45:21 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	key_press(int keycode, t_g *g)
{
	if (keycode == ESCAPE)
	{
		mlx_clear_window(g->data.mlx, g->data.win);
		mlx_destroy_window(g->data.mlx, g->data.win);
		exit(0);
	}
	return(0);
}

int	ft_exit(t_g *g)
{
	mlx_destroy_window(g->data.mlx, g->data.win);
	exit(0);
}
