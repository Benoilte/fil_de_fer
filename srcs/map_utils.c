/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:10:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_x_offset(t_fdf *fdf)
{
	fdf->map->x_offset = ((WIN_WIDTH / 2) - fdf->map->x_min)
		- ((fdf->map->x_max - fdf->map->x_min) / 2);
}

void	get_y_offset(t_fdf *fdf)
{
	fdf->map->y_offset = ((WIN_HEIGHT / 2) - fdf->map->y_min)
		- ((fdf->map->y_max - fdf->map->y_min) / 2);
}

void	update_size(t_fdf *fdf)
{
	while ((fdf->map->x_max + fdf->map->x_offset > WIN_WIDTH
			|| fdf->map->x_min + fdf->map->x_offset < 0)
		&& fdf->map->size > 1)
	{
		fdf->map->x_max = 0;
		fdf->map->x_min = WIN_WIDTH;
		fdf->map->size--;
		update_map(fdf);
	}
	while ((fdf->map->y_max + fdf->map->y_offset > WIN_HEIGHT
			|| fdf->map->y_min + fdf->map->y_offset < 0)
		&& fdf->map->z_fact > 0)
	{
		fdf->map->y_max = 0;
		fdf->map->y_min = WIN_HEIGHT;
		fdf->map->z_fact--;
		update_map(fdf);
	}
}

void	update_map(t_fdf *fdf)
{
	update_matrix(fdf);
	get_x_offset(fdf);
	get_y_offset(fdf);
}

void	replace_map(t_fdf *fdf)
{
	if (fdf->map->zoom < 0)
		fdf->map->zoom = 0;
	update_matrix(fdf);
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->img.img);
	draw_map(fdf);
}
