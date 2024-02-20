/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:41:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/20 17:15:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_point(t_master *master, int x, int y, char *val)
{
	char	**z_and_col;
	t_point	*point;

	point = (master->map->matrix)[y][x];
	point->x = (x * master->map->iso->size);
	point->y = (y * master->map->iso->size);
	if (ft_strchr(val, ','))
	{
		z_and_col = ft_split(val, ',');
		is_malloc_or_exit(master, z_and_col, "Memory allocation, fill_point()");
		point->z = ft_atoi(*z_and_col);
		point->z_iso = point->z * master->map->iso->z_fact;
		cart_to_iso(master, point);
		ft_strlcpy(point->color, z_and_col[1], 10);
		free_strstr(z_and_col);
	}
	else
	{
		point->z = ft_atoi(val);
		point->z_iso = point->z * master->map->iso->z_fact;
		cart_to_iso(master, point);
	}
}

void	update_point(t_master *master, int x, int y)
{
	t_point	*point;

	point = (master->map->matrix)[y][x];
	point->x = (x * master->map->iso->size * master->map->zoom);
	point->y = (y * master->map->iso->size * master->map->zoom);
	point->z_iso = point->z * master->map->iso->z_fact * master->map->zoom;
	cart_to_iso(master, point);
}

void	rotate_point(t_master *master, int x, int y, int angle)
{
	t_point	*point;
	// int		x_orig;
	// int		x_pos;
	// double	vec_size;
	// double	x_angle;
	int		new_y;
	int		new_z;
	// int		vector_size;

	point = (master->map->matrix)[y][x];
	// vec_size = sqrt(pow())
	// x_orig = ((master->map->matrix)[0][0])->x_iso_dst;
	new_y = (point->y_iso_dst * cos(angle)) - (point->z_iso * sin(angle));
	new_z = (point->y_iso_dst * sin(angle)) + (point->z_iso * cos(angle));
	point->y_iso_dst = new_y;
	point->z_iso = new_z;
	cart_to_iso(master, point);
}

void	cart_to_iso(t_master *master, t_point *point)
{
	int	x;
	int	y;
	int	z;

	(void)master;
	x = point->x;
	y = point->y;
	z = point->z_iso;
	point->x_iso_dst = x_cart_to_iso(x, y, z);
	point->y_iso_dst = y_cart_to_iso(x, y, z);
}

int	x_cart_to_iso(int x, int y, int z)
{
	return (x * cos(120) + y * cos(120 + 2) + z * cos(120 - 2));
}

int	y_cart_to_iso(int x, int y, int z)
{
	return (x * sin(120) + y * sin(120 + 2) + z * sin(120 - 2));
}
