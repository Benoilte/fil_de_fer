/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/29 11:06:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_x_offset(t_fdf *fdf)
{
	fdf->camera->x_offset = (((WIN_WIDTH - MENU_W) / 2) - fdf->map->x_min)
		- ((fdf->map->x_max - fdf->map->x_min) / 2);
}

void	get_y_offset(t_fdf *fdf)
{
	fdf->camera->y_offset = ((WIN_HEIGHT / 2) - fdf->map->y_min)
		- ((fdf->map->y_max - fdf->map->y_min) / 2);
}

void	update_size(t_fdf *fdf)
{
	while ((fdf->map->x_max + fdf->camera->x_offset > (WIN_WIDTH - MENU_W)
			|| fdf->map->x_min + fdf->camera->x_offset < 0)
		&& fdf->camera->size > 1)
	{
		fdf->camera->size--;
		update_map(fdf);
	}
	while ((fdf->map->y_max + fdf->camera->y_offset > WIN_HEIGHT
			|| fdf->map->y_min + fdf->camera->y_offset < 0)
		&& fdf->camera->z_fact > 0)
	{
		if (fdf->camera->projection == ISO)
			fdf->camera->z_fact--;
		else
			fdf->camera->size--;
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
	if (fdf->camera->zoom < 0)
		fdf->camera->zoom = 0;
	update_matrix(fdf);
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->img.img);
	draw_map(fdf);
}
