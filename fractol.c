/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:27:06 by abello-r          #+#    #+#             */
/*   Updated: 2021/06/22 12:31:03 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		write(1, RED ERROR_ARG"\n", 51);
		return (1);
	}
	else if (argc == 2)
	{
		if ((ft_strcmp(argv[1], "Julia") == 1)
			&& (ft_strcmp(argv[1], "Mandelbrot") == 1))
		{
			write(1, RED ERROR_ARG"\n", 51);
			return (1);
		}
	}
	
	return (0);
}
