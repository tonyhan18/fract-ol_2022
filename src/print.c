/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:03:06 by chahan            #+#    #+#             */
/*   Updated: 2022/03/12 18:17:34 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_errors(char *str)
{
	printf("Error\n");
	printf(RED "%s\n" RESET, str);
	exit(1);
}
