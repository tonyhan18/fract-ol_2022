/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:02:58 by chahan            #+#    #+#             */
/*   Updated: 2022/03/12 18:02:59 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	move_keys(t_fractol *fractol)
{
	if (fractol->move_down)
		fractol->moveY += 0.0003 * FRAME_TIME / fractol->zoom;
	if (fractol->move_up)
		fractol->moveY -= 0.0003 * FRAME_TIME / fractol->zoom;
	if (fractol->move_right)
		fractol->moveX += 0.0003 * FRAME_TIME / fractol->zoom;
	if (fractol->move_left)
		fractol->moveX -= 0.0003 * FRAME_TIME / fractol->zoom;
}

void	fractal_keys(t_fractol *fractol)
{
	if (fractol->zoom_in)
	{
		fractol->zoom *= pow(1.001, FRAME_TIME);
		fractol->zoom_in = 0;
	}
	if (fractol->zoom_out)
	{
		fractol->zoom /= pow(1.001, FRAME_TIME);
		fractol->zoom_out = 0;
	}
	if (fractol->more_iter)
	{
		fractol->maxIterations += 4;
		fractol->more_iter = 0;
	}
	if (fractol->less_iter)
	{
		if (fractol->maxIterations > 4)
			fractol->maxIterations -= 4;
	}
	move_keys(fractol);
}
