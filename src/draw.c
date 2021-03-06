/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:01:49 by chahan            #+#    #+#             */
/*   Updated: 2022/03/12 20:53:04 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	set_color(t_fractol *fractol, int *i)
{
	int	r;
	int	g;
	int	b;

	if (!fractol->bonus)
	{
		fractol->random = 2;
		fractol->random_two = 4;
	}
	g = (int)(255 * ((double)*i / (double)fractol->maxIterations));
	r = ((255 - g) * 0.60) * fabs(cos(fractol->random));
	b = ((255 - g) * 0.2) * fabs(sin(fractol->random_two));
	fractol->color = create_trgb(0, r * fractol->random, g
			* asin((double)fractol->maxIterations),
			b * (double)fractol->maxIterations);
	if (g == 255)
		fractol->color = create_trgb(0, 0, 0, 0);
}

static void	set_text(t_fractol *fractol)
{
	if (fractol->julia.selected)
		mlx_string_put(fractol->mlx, fractol->window, 10, 25,
			15770880, "Julia");
	else if (fractol->mdlbr.selected)
		mlx_string_put(fractol->mlx, fractol->window, 10, 25,
			15770880, "Mandelbrot");
	else if (fractol->sierpinski.selected)
		mlx_string_put(fractol->mlx, fractol->window, 10, 25,
			15770880, "Sierpinski");
}

int	fractals(t_fractol *fractol)
{
	if (fractol->bonus)
	{
		fractol->random += 0.025;
		fractol->random_two += 0.010;
	}
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, fractol->window);
	if (fractol->julia.selected)
		julia(fractol);
	else if (fractol->mdlbr.selected)
		mandelbrot(fractol);
	else if (fractol->sierpinski.selected)
		sierpinski(fractol);
	fractal_keys(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->main_img.img, 0, 0);
	if (fractol->bonus)
		set_text(fractol);
	return (0);
}
