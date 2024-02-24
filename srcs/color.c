/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:05:43 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/24 14:23:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_perc(double start, double end, double size)
{
	return (fabs(end - start) / size);
}

int	get_color(int color1, int color2, float fraction)
{
	t_color	color;

	color.r1 = (color1 >> 16) & 0xFF;
	color.r2 = (color2 >> 16) & 0xFF;
	color.g1 = (color1 >> 8) & 0xFF;
	color.g2 = (color2 >> 8) & 0xFF;
	color.b1 = color1 & 0xFF;
	color.b2 = color2 & 0xFF;
	return ((int)((color.r2 - color.r1) * fraction + color.r1) << 16) |
		((int)((color.g2 - color.g1) * fraction + color.g1) << 8) |
		(int)((color.b2 - color.b1) * fraction + color.b1);
}
