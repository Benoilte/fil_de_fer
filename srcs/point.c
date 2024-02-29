/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:41:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/29 12:31:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_point(t_fdf *fdf, int x, int y, char *val)
{
	char	**z_and_col;
	t_point	*point;

	point = (fdf->map->matrix)[y][x];
	point->x = (x * fdf->camera->size);
	point->y = (y * fdf->camera->size);
	if (ft_strchr(val, ','))
	{
		z_and_col = ft_split(val, ',');
		is_malloc_or_exit(fdf, z_and_col, "Memory allocation, fill_point()");
		point->z = ft_atoi(*z_and_col);
		point->z_proj = point->z * fdf->camera->z_fact;
		set_projection(fdf, point);
		point->color = ft_atoh(z_and_col[1]);
		free_strstr(z_and_col);
		fdf->map->color_is_set = 1;
	}
	else
	{
		point->z = ft_atoi(val);
		point->color = WHITE;
		point->z_proj = point->z * fdf->camera->z_fact;
		set_projection(fdf, point);
	}
}

void	update_point(t_fdf *fdf, int x, int y)
{
	t_point	*point;

	point = (fdf->map->matrix)[y][x];
	point->x = (x * fdf->camera->size * fdf->camera->zoom);
	point->y = (y * fdf->camera->size * fdf->camera->zoom);
	point->z_proj = point->z * fdf->camera->z_fact * fdf->camera->zoom;
	if (fdf->map->color_is_set == 0)
		point->color = get_color(fdf->map->color_1, fdf->map->color_2,
				get_perc(point->z,
					fdf->map->z_max,
					fdf->map->z_max - fdf->map->z_min));
	rotate_x(fdf, x, y);
	rotate_y(fdf, x, y);
	rotate_z(fdf, x, y);
	set_projection(fdf, point);
}

/*
** Convert coordinate to iso projection
*/

void	set_projection(t_fdf *fdf, t_point *point)
{
	double	angle;

	angle = 30 * (M_PI / 180);
	if (fdf->camera->projection == ISO)
	{
		point->x_proj = (point->x - point->y) * cos(angle);
		point->y_proj = -(point->z_proj) + (point->x + point->y) * sin(angle);
	}
	else
	{
		point->x_proj = point->x;
		point->y_proj = point->y;
	}
}
