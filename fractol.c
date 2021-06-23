/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:27:06 by abello-r          #+#    #+#             */
/*   Updated: 2021/06/23 11:17:02 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	main(int argc, char **argv)
{
	t_data	data;

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
	if (ft_strcmp(argv[1], "Julia"))
			ft_julia(&data);
	if (ft_strcmp(argv[1], "Mandelbrot"))
			ft_mandelbrot(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenght, &data.endian);
	mlx_loop(data.mlx);

	return (0);
}
