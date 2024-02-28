/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:29:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:55:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(t_fdf *fdf, char axis, double angle)
{
	if (axis == 'x')
		fdf->camera->rot_x += angle;
	if (axis == 'y')
		fdf->camera->rot_y += angle;
	if (axis == 'z')
		fdf->camera->rot_z += angle;
	replace_map(fdf);
}

void	rotate_x(t_fdf *fdf, int x, int y)
{
	t_point	*point;
	int		new_y;
	int		new_z;
	double	angle;

	angle = fdf->camera->rot_x * (M_PI / 180);
	point = (fdf->map->matrix)[y][x];
	new_y = ((point->y) * cos(angle)) - ((point->z_proj) * sin(angle));
	new_z = ((point->y) * sin(angle)) + ((point->z_proj) * cos(angle));
	point->y = new_y;
	point->z_proj = new_z;
}

void	rotate_y(t_fdf *fdf, int x, int y)
{
	t_point	*point;
	int		new_x;
	int		new_z;
	double	angle;

	angle = fdf->camera->rot_y * (M_PI / 180);
	point = (fdf->map->matrix)[y][x];
	new_x = ((point->x) * cos(angle)) - ((point->z_proj) * sin(angle));
	new_z = ((point->x) * sin(angle)) + ((point->z_proj) * cos(angle));
	point->x = new_x;
	point->z_proj = new_z;
}

void	rotate_z(t_fdf *fdf, int x, int y)
{
	t_point	*point;
	int		new_x;
	int		new_y;
	double	angle;

	angle = fdf->camera->rot_z * (M_PI / 180);
	point = (fdf->map->matrix)[y][x];
	new_x = ((point->x) * cos(angle)) - ((point->y) * sin(angle));
	new_y = ((point->x) * sin(angle)) + ((point->y) * cos(angle));
	point->x = new_x;
	point->y = new_y;
}
