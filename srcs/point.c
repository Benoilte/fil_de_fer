/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:41:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/14 13:44:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_point(t_master *master, int x, int y, char *val)
{
	char	**z_and_col;
	t_point	*point;

	point = (master->map->matrix)[y][x];
	point->x = (x * master->map->point_dist);
	point->y = (y * master->map->point_dist);
	if (ft_strchr(val, ','))
	{
		z_and_col = ft_split(val, ',');
		is_malloc_or_exit(master, z_and_col, "Memory allocation, fill_point()");
		point->z = ft_atoi(*z_and_col) * 3;
		cart_to_iso(master, point);
		ft_strlcpy(point->color, z_and_col[1], 10);
		free_strstr(z_and_col);
	}
	else
	{
		point->z = ft_atoi(val) * 3;
		cart_to_iso(master, point);
	}
}

void	cart_to_iso(t_master *master, t_point *point)
{
	int	x;
	int	y;
	int	z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x_iso_dst = x_cart_to_iso(x, y, z) + master->map->iso_width_offset;
	point->y_iso_dst = y_cart_to_iso(x, y, z) + master->map->iso_height_offset;
}

int	x_cart_to_iso(int x, int y, int z)
{
	return (x * cos(120) + y * cos(120 + 2) + z * cos(120 - 2));
}

int	y_cart_to_iso(int x, int y, int z)
{
	return (x * sin(120) + y * sin(120 + 2) + z * sin(120 - 2));
}
