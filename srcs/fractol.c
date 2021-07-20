/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:27:06 by abello-r          #+#    #+#             */
/*   Updated: 2021/07/19 16:00:18 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lotcraf.h"

int	main(int argc, char **argv)
{
	t_g g;

	if (argc < 2 || argc > 3)
	{
		write(1, RED ERROR_ARG"\n", 46);
		return (1);
	}
	else if (argc == 3 || argc == 2)
	{
		if ((ft_strcmp(argv[1], "Julia") == 1)
			&& (ft_strcmp(argv[1], "Mandelbrot") == 1))
		{
			write(1, RED ERROR_ARG"\n", 46);
			return (1);
		}
	}
	if (argc == 2 || argc == 3)
		ft_param_color(&g, argc, argv);

	ft_init_structs(&g);

	g.data.mlx = mlx_init();
	g.data.win = mlx_new_window(g.data.mlx, WIDTH, HEIGHT, "Fract-ol");
	g.data.img = mlx_new_image(g.data.mlx, WIDTH, HEIGHT);
	g.data.addr = mlx_get_data_addr(g.data.img, &g.data.bits_per_pixel, &g.data.line_lenght, &g.data.endian);

	if (ft_strcmp(argv[1], "Julia") == 0)
		mlx_loop_hook(g.data.mlx, ft_julia, &g);
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		mlx_loop_hook(g.data.mlx, ft_mandelbrot, &g);

	mlx_hook(g.data.win, 02, (0L << 0), key_press, &g);
	mlx_hook(g.data.win, 03, (0L << 0), key_release, &g);
	mlx_hook(g.data.win, 17, (17L << 0), ft_exit, &g);


	mlx_hook(g.data.win, 9, (1L << 4), ft_in_win, &g);
	mlx_hook(g.data.win, 10, (1L << 5), ft_leave_win, &g);



	mlx_loop(g.data.mlx);

	return (0);
}

