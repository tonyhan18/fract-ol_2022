/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:02:27 by chahan            #+#    #+#             */
/*   Updated: 2022/03/20 14:54:07 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	initialize_fractals(t_fractol *fractol)
{
	fractol->zoom = 0.5;
	fractol->moveX = 0;
	fractol->moveY = 0;
	fractol->maxIterations = 25;
	fractol->julia.cRe = -0.7;
	fractol->julia.cIm = 0.27015;
}

static void	setup(t_fractol *fractol, char **argv)
{
	if (ft_strcmp("julia", argv[1]))
		fractol->julia.selected = 1;
	if (ft_strcmp("mandelbrot", argv[1]))
		fractol->mdlbr.selected = 1;
	if (ft_strcmp("sierpinski", argv[1]))
		fractol->sierpinski.selected = 1;
	fractol->main_img.img = mlx_new_image(fractol->mlx,
			fractol->screen.x, fractol->screen.y);
	fractol->main_img.addr = mlx_get_data_addr(fractol->main_img.img,
			&fractol->main_img.bpp, &fractol->main_img.line_l,
			&fractol->main_img.endian);
	initialize_fractals(fractol);
	mlx_hook(fractol->window, KEY_PRESS, 1L << 0, keys, fractol);
	mlx_hook(fractol->window, KEY_RELEASE, 1L << 1, keys_release, fractol);
	mlx_hook(fractol->window, DESTROY_NOTIFY, 0L, finish, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_loop_hook(fractol->mlx, fractals, fractol);
	mlx_loop(fractol->mlx);
}

static void	print_ignored_args(int argc, char **argv, t_fractol *fractol)
{
	int	i;

	i = 2;
	if (argc > 2)
	{
		printf("This Parameter is not acceptable:\n");
		while (i < argc)
		{
			if (ft_strcmp("--fullscreen", argv[i]))
				mlx_get_screen_size(fractol->mlx,
					&fractol->screen.x, &fractol->screen.y);
			else
				printf(RED "\t·%s\n" RESET, argv[i]);
			i++;
		}
	}
}

static void	run(char **argv, t_fractol *fractol, int argc)
{
	if (!ft_strcmp("julia", argv[1]) && !ft_strcmp("mandelbrot", argv[1])
		&& !ft_strcmp("sierpinski", argv[1]))
	{
		printf(RED "Error!\nUnknown set: \"%s\"" RESET
			   "\nTry with:\n\t·julia\n\t·mandelbrot\n\t·sierpinski\n"
			"\nOptions :\"--fullscreen\" for fullscreen mode\n",
			argv[1]);
		exit(1);
	}
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		print_errors(RED "\tError! : Problem with MiniLibx");
	fractol->screen.x = 1000;
	fractol->screen.y = 1000;
	print_ignored_args(argc, argv, fractol);
	fractol->window = mlx_new_window(fractol->mlx, fractol->screen.x,
			fractol->screen.y, "fract-ol");
	if (!(fractol->window))
		print_errors(RED "\tError! : Problem opening a new Window");
	setup(fractol, argv);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	ft_bzero(&fractol, sizeof(t_fractol));
	fractol.bonus = 1;
	if (argc < 2)
	{
		printf(RED "Error\nA parameter is needed" RESET
			"\nTry with:\n\t·julia\n\t·mandelbrot\n\t·sierpinski\n"
			"\nOptions :\"--fullscreen\" for fullscreen mode\n");
		exit(1);
	}
	if (argc >= 2)
	{
		if (!(ft_strcmp("fractol", argv[0]) || ft_strcmp("./fractol", argv[0])))
			print_errors("Executable must be a \"fractol [file] [options]");
		run(argv, &fractol, argc);
	}
	return (0);
}
