/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:02:00 by chahan            #+#    #+#             */
/*   Updated: 2022/03/20 14:54:00 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	juliamain(int *i, t_fractol *fractol)
{
	while (*i < fractol->maxIterations)
	{
		fractol->julia.oldRe = fractol->julia.newRe;
		fractol->julia.oldIm = fractol->julia.newIm;
		fractol->julia.newRe = fractol->julia.oldRe * fractol->julia.oldRe
			- fractol->julia.oldIm * fractol->julia.oldIm + fractol->julia.cRe;
		fractol->julia.newIm = 2 * fractol->julia.oldRe
			* fractol->julia.oldIm + fractol->julia.cIm;
		if ((fractol->julia.newRe * fractol->julia.newRe
				+ fractol->julia.newIm * fractol->julia.newIm) > 4)
			break ;
		*i += 1;
	}
}

int	julia(t_fractol *fractol)
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
			fractol->julia.newRe = 1.5 * (x - fractol->screen.y / 2)
				/ (0.5 * fractol->zoom * fractol->screen.x) + fractol->moveX;
			fractol->julia.newIm = (y - fractol->screen.y / 2)
				/ (0.5 * fractol->zoom * fractol->screen.y) + fractol->moveY;
			i = 0;
			juliamain(&i, fractol);
			set_color(fractol, &i);
			my_pixel_put(&fractol->main_img, x, y, fractol->color);
			x++;
		}
		y++;
	}
	return (0);
}
