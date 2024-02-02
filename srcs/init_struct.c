/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:21:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/02 11:35:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_master	*init_master(void)
{
	t_master	*master;

	master = (t_master *)malloc(1 * sizeof(t_master));
	if (!master)
		cleanup_and_exit(master, "Memory allocation, init_master()", 1);
	master->map_file = NULL;
	master->map = NULL;
	return (master);
}

t_map	*init_map(t_master *master)
{
	t_map	*map;

	map = (t_map *)malloc(1 * sizeof(t_map));
	if (!map)
		cleanup_and_exit(master, "Memory allocation, init_map()", 1);
	map->matrix = NULL;
	return (map);
}

t_point	*init_point(t_master *master)
{
	t_point	*point;

	point = (t_point *)malloc(1 * sizeof(t_point));
	if (!point)
		cleanup_and_exit(master, "Memory allocation, init_point()", 1);
	point->color = NULL;
	return (point);
}
