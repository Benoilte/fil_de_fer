/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:41:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/27 22:53:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_point(t_master *master, int x, int y, char *val)
{
	char	**z_and_col;
	t_point	*point;

	point = (master->map->matrix)[y][x];
	point->x = (x * master->map->size);
	point->y = (y * master->map->size);
	if (ft_strchr(val, ','))
	{
		z_and_col = ft_split(val, ',');
		is_malloc_or_exit(master, z_and_col, "Memory allocation, fill_point()");
		point->z = ft_atoi(*z_and_col);
		point->z_proj = point->z * master->map->z_fact;
		iso(point);
		point->color = ft_atoh(z_and_col[1]);
		free_strstr(z_and_col);
		master->map->color_is_set = 1;
	}
	else
	{
		point->z = ft_atoi(val);
		point->color = WHITE;
		point->z_proj = point->z * master->map->z_fact;
		iso(point);
	}
}

void	update_point(t_master *master, int x, int y)
{
	t_point	*point;

	point = (master->map->matrix)[y][x];
	point->x = (x * master->map->size * master->map->zoom);
	point->y = (y * master->map->size * master->map->zoom);
	point->z_proj = point->z * master->map->z_fact * master->map->zoom;
	if (master->map->color_is_set == 0)
		point->color = get_color(PURPLE, GOLD,
				get_perc(point->z,
					master->map->z_max,
					master->map->z_max - master->map->z_min));
	rotate_x(master, x, y);
	rotate_y(master, x, y);
	rotate_z(master, x, y);
	iso(point);
}

/*
** Convert coordinate to iso projection
*/

void	iso(t_point *point)
{
	double	angle;

	angle = 30 * (M_PI / 180);
	point->x_proj = (point->x - point->y) * cos(angle);
	point->y_proj = -(point->z_proj) + (point->x + point->y) * sin(angle);
}

