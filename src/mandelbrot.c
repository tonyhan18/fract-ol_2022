/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:02:49 by chahan            #+#    #+#             */
/*   Updated: 2022/03/12 18:02:51 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	maindelbrot(t_fractol *fractol, int *x, int *y, int *i)
{
	fractol->mdlbr.pr = 1.5 * (*x - fractol->screen.x / 2)
		/ (0.5 * fractol->zoom * fractol->screen.x)
		+ fractol->moveX;
	fractol->mdlbr.pi = (*y - fractol->screen.y / 2)
		/ (0.5 * fractol->zoom * fractol->screen.y)
		+ fractol->moveY;
	fractol->mdlbr.oldIm = 0;
	fractol->mdlbr.oldRe = fractol->mdlbr.oldIm;
	fractol->mdlbr.newIm = fractol->mdlbr.oldRe;
	fractol->mdlbr.newRe = fractol->mdlbr.newIm;
	*i = 0;
	while (*i < fractol->maxIterations)
	{
		fractol->mdlbr.oldRe = fractol->mdlbr.newRe;
		fractol->mdlbr.oldIm = fractol->mdlbr.newIm;
		fractol->mdlbr.newRe = fractol->mdlbr.oldRe
			* fractol->mdlbr.oldRe - fractol->mdlbr.oldIm
			* fractol->mdlbr.oldIm + fractol->mdlbr.pr;
		fractol->mdlbr.newIm = 2 * fractol->mdlbr.oldRe
			* fractol->mdlbr.oldIm + fractol->mdlbr.pi;
		if ((fractol->mdlbr.newRe * fractol->mdlbr.newRe
				+ fractol->mdlbr.newIm * fractol->mdlbr.newIm) > 4)
			break ;
		*i += 1;
	}
}

//int random = (rand() % (10 - 3 + 1) + 3);
//color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));

int	mandelbrot(t_fractol *fractol)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	while (y < fractol->screen.y)
	{
		x = 0;
		while (x < fractol->screen.x)
		{
			maindelbrot(fractol, &x, &y, &i);
			set_color(fractol, &i);
			my_pixel_put(&fractol->main_img, x, y, fractol->color);
			x++;
		}
		y++;
	}
	return (0);
}
