/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:02:11 by chahan            #+#    #+#             */
/*   Updated: 2022/03/12 20:15:57 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	finish(t_fractol *fractol)
{
	fractol->mdlbr.selected = 0;
	fractol->julia.selected = 0;
	fractol->sierpinski.selected = 0;
	printf(GREEN "Thank you for using\n" RESET);
	exit(0);
}

int	keys(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		finish(fractol);
	if (fractol->bonus)
	{
		if (keycode == K_DOWN || keycode == K_S)
			fractol->move_down = 1;
		if (keycode == K_LEFT || keycode == K_A)
			fractol->move_left = 1;
		if (keycode == K_RIGHT || keycode == K_D)
			fractol->move_right = 1;
		if (keycode == K_UP || keycode == K_W)
			fractol->move_up = 1;
		if (keycode == K_PLUS)
			fractol->more_iter = 1;
		if (keycode == K_LESS)
			fractol->less_iter = 1;
	}
	return (keycode);
}

static void	key_julia(int keycode, t_fractol *fractol)
{
	if (keycode == K_ONE)
		fractol->julia.cIm += 0.0002 * FRAME_TIME / fractol->zoom;
	if (keycode == K_TWO)
		fractol->julia.cIm -= 0.0002 * FRAME_TIME / fractol->zoom;
	if (keycode == K_THREE)
		fractol->julia.cRe += 0.0002 * FRAME_TIME / fractol->zoom;
	if (keycode == K_FOUR)
		fractol->julia.cRe -= 0.0002 * FRAME_TIME / fractol->zoom;
}

int	keys_release(int keycode, t_fractol *fractol)
{
	if (fractol->bonus)
	{
		if (keycode == K_DOWN || keycode == K_S)
			fractol->move_down = 0;
		if (keycode == K_LEFT || keycode == K_A)
			fractol->move_left = 0;
		if (keycode == K_RIGHT || keycode == K_D)
			fractol->move_right = 0;
		if (keycode == K_UP || keycode == K_W)
			fractol->move_up = 0;
		if (keycode == K_PLUS)
			fractol->more_iter = 0;
		if (keycode == K_LESS)
			fractol->less_iter = 0;
		if (keycode == K_ENTER)
			change_fractal(fractol);
		key_julia(keycode, fractol);
	}
	return (keycode);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	mlx_mouse_get_pos(fractol->window, &x, &y);
	if (keycode == SCROLL_UP && fractol->zoom > 0.1)
		fractol->zoom_in = 1;
	if (keycode == SCROLL_DOWN)
		fractol->zoom_out = 1;
	return (0);
}
