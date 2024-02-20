/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:29:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/20 14:41:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(t_master *master, int angle)
{
	int		x;
	int		y;

	y = 0;
	while ((master->map->matrix)[y])
	{
		x = 0;
		while ((master->map->matrix)[y][x])
		{
			rotate_point(master, x, y, angle);
			get_min_max(master, (master->map->matrix)[y][x]);
			x++;
		}
		y++;
	}
    mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
    draw_map(master);
}
