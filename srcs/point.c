/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:41:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/06 19:07:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_point(t_master *master, int x, int y, char *val)
{
	char	**z_and_col;
	t_point	*point;

	point = (master->map->matrix)[y][x];
	// point->x = (x * master->map->step) + master->map->width_offset;
	// point->y = (y * master->map->step) + master->map->height_offset;
	point->x = (x * master->map->step);
	point->y = (y * master->map->step);
	if (ft_strchr(val, ','))
	{
		z_and_col = ft_split(val, ',');
		is_malloc_or_exit(master, z_and_col, "Memory allocation, fill_point()");
		point->z = ft_atoi(*z_and_col);
		cart_to_iso(master, point, x, y);
		ft_strlcpy(point->color, z_and_col[1], 10);
		free_strstr(z_and_col);
	}
	else
	{
		point->z = ft_atoi(val);
		cart_to_iso(master, point, x, y);
	}
}

// destination.x = source.x + cos(angle) * source.z
// destination.y = source.y + sin(angle) * source.z

void	cart_to_iso(t_master *master, t_point *point, int x, int y)
{
	int	iso_height_offset;

	(void)x;
	(void)y;
	iso_height_offset = ((((master->map->width * master->map->step) * sin(120)) + ((master->map->height * master->map->step) * sin(120 + 2))) / 2);
	point->x_iso_dst = (point->x * cos(120) + point->y * cos(120 + 2) + point->z * cos(120 - 2)) + master->map->width_offset;
	point->y_iso_dst = (point->x * sin(120) + point->y * sin(120 + 2) + point->z * sin(120 - 2)) + ((WIN_HEIGHT / 2) - iso_height_offset);
	// point->x_iso_dst = (point->x - point->y) + master->map->width_offset;
	// point->y_iso_dst = (((point->x + point->y) / 2) + master->map->height_offset);
}
