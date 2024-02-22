/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:29:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/22 11:07:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(t_master *master, char axis, double angle)
{
	if (axis == 'x')
		master->map->rot_x += angle;
	if (axis == 'y')
		master->map->rot_y += angle;
	if (axis == 'z')
		master->map->rot_z += angle;
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	update_matrix(master);
	draw_map(master);
}

void	rotate_x(t_master *master, int x, int y)
{
	t_point	*point;
	int		new_y;
	int		new_z;
	double	angle;

	angle = master->map->rot_x * (M_PI / 180);
	point = (master->map->matrix)[y][x];
	new_y = ((point->y) * cos(angle)) - ((point->z_iso) * sin(angle));
	new_z = ((point->y) * sin(angle)) + ((point->z_iso) * cos(angle));
	point->y = new_y;
	point->z_iso = new_z;
}

void	rotate_y(t_master *master, int x, int y)
{
	t_point	*point;
	int		new_x;
	int		new_z;
	double	angle;

	angle = master->map->rot_y * (M_PI / 180);
	point = (master->map->matrix)[y][x];
	new_x = ((point->x) * cos(angle)) - ((point->z_iso) * sin(angle));
	new_z = ((point->x) * sin(angle)) + ((point->z_iso) * cos(angle));
	point->x = new_x;
	point->z_iso = new_z;
}

void	rotate_z(t_master *master, int x, int y)
{
	t_point	*point;
	int		new_x;
	int		new_y;
	double	angle;

	angle = master->map->rot_z * (M_PI / 180);
	point = (master->map->matrix)[y][x];
	new_x = ((point->x) * cos(angle)) - ((point->y) * sin(angle));
	new_y = ((point->x) * sin(angle)) + ((point->y) * cos(angle));
	point->x = new_x;
	point->y = new_y;
}
