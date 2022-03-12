/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:01:37 by chahan            #+#    #+#             */
/*   Updated: 2022/03/12 20:11:09 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_fractal(int mdlbr, int julia, int si, t_fractol *fractol)
{
	fractol->julia.selected = julia;
	fractol->mdlbr.selected = mdlbr;
	fractol->sierpinski.selected = si;
}

void	change_fractal(t_fractol *fractol)
{
	if (fractol->julia.selected)
		set_fractal(1, 0, 0, fractol);
	else if (fractol->mdlbr.selected)
		set_fractal(0, 0, 1, fractol);
	else if (fractol->sierpinski.selected)
		set_fractal(0, 1, 0, fractol);
}
