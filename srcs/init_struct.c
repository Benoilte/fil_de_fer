/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:21:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/27 13:49:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_master	*init_master(char *file)
{
	t_master	*master;

	master = (t_master *)malloc(1 * sizeof(t_master));
	is_malloc_or_exit(master, master, "Memory allocation, init_master()");
	master->file_name = file;
	master->file_lst = NULL;
	master->map = NULL;
	return (master);
}

t_map	*init_map(t_master *master)
{
	t_map	*map;

	map = (t_map *)malloc(1 * sizeof(t_map));
	is_malloc_or_exit(master, map, "Memory allocation, init_map()");
	map->matrix = NULL;
	map->color_is_set = 0;
	map->zoom = 1;
	map->rot_x = 0;
	map->rot_y = 0;
	map->rot_z = 0;
	map->x_max = 0;
	map->x_min = WIN_WIDTH;
	map->y_max = 0;
	map->y_min = WIN_HEIGHT;
	map->z_max = 0;
	map->z_min = 0;
	map->z_fact = 0;
	map->x_offset = 0;
	map->y_offset = 0;
	map->size = 0;
	return (map);
}

t_point	*init_point(t_master *master)
{
	t_point	*point;

	point = (t_point *)malloc(1 * sizeof(t_point));
	is_malloc_or_exit(master, point, "Memory allocation, init_point()");
	return (point);
}

