/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:21:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 11:43:35 by bebrandt         ###   ########.fr       */
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
	master->mlx = NULL;
	master->data_img = NULL;
	return (master);
}

t_map	*init_map(t_master *master)
{
	t_map	*map;

	map = (t_map *)malloc(1 * sizeof(t_map));
	is_malloc_or_exit(master, map, "Memory allocation, init_map()");
	map->cart = NULL;
	map->iso = NULL;
	map->matrix = NULL;
	map->cart = (t_cart *)malloc(1 * sizeof(t_cart));
	is_malloc_or_exit(master, map->cart, "Memory allocation, init_map->cart()");
	map->iso = (t_iso *)malloc(1 * sizeof(t_iso));
	is_malloc_or_exit(master, map->iso, "Memory allocation, init_map->iso()");
	return (map);
}

t_point	*init_point(t_master *master)
{
	t_point	*point;

	point = (t_point *)malloc(1 * sizeof(t_point));
	is_malloc_or_exit(master, point, "Memory allocation, init_point()");
	return (point);
}
