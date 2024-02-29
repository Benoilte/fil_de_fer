/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:21:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/29 12:30:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(1 * sizeof(t_fdf));
	is_malloc_or_exit(fdf, fdf, "Memory allocation, init_fdf()");
	fdf->file_name = file;
	fdf->file_lst = NULL;
	fdf->map = NULL;
	fdf->camera = NULL;
	return (fdf);
}

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(1 * sizeof(t_camera));
	is_malloc_or_exit(fdf, camera, "Memory allocation, init_camera()");
	camera->zoom = 1;
	camera->z_fact = 1;
	camera->size = 0;
	camera->rot_x = 0;
	camera->rot_y = 0;
	camera->rot_z = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->projection = 0;
	return (camera);
}

t_map	*init_map(t_fdf *fdf)
{
	t_map	*map;

	map = (t_map *)malloc(1 * sizeof(t_map));
	is_malloc_or_exit(fdf, map, "Memory allocation, init_map()");
	map->matrix = NULL;
	map->color_is_set = 0;
	map->color_1 = PURPLE;
	map->color_2 = GOLD;
	map->x_max = INT_MIN;
	map->x_min = INT_MAX;
	map->y_max = INT_MIN;
	map->y_min = INT_MAX;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

t_point	*init_point(t_fdf *fdf)
{
	t_point	*point;

	point = (t_point *)malloc(1 * sizeof(t_point));
	is_malloc_or_exit(fdf, point, "Memory allocation, init_point()");
	return (point);
}
