/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:41:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/24 16:22:36 by bebrandt         ###   ########.fr       */
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
		point->color = ft_atoh(z_and_col[1]);
		free_strstr(z_and_col);
		master->map->color_is_set = 1;
	}
	else
	{
		point->z = ft_atoi(val);
		point->color = WHITE;
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
	if (master->map->color_is_set == 0)
		point->color = get_color(PURPLE, GOLD,
				get_perc(point->z,
					master->map->iso->z_max,
					master->map->iso->z_max - master->map->iso->z_min));
	rotate_x(master, x, y);
	rotate_y(master, x, y);
	rotate_z(master, x, y);
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
	double	angle;
	double	offset;

	angle = 30 * (M_PI / 180);
	offset = 120 * (M_PI / 180);
	return (x * cos(angle) + y * cos(angle + offset) + z * cos(angle - offset));
}

int	y_cart_to_iso(int x, int y, int z)
{
	double	angle;
	double	offset;

	angle = 30 * (M_PI / 180);
	offset = 120 * (M_PI / 180);
	return (x * sin(angle) + y * sin(angle + offset) + z * sin(angle - offset));
}
