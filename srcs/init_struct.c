/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:21:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 16:54:56 by bebrandt         ###   ########.fr       */
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
	map->cart = NULL;
	map->iso = NULL;
	map->matrix = NULL;
	map->cart = (t_cart *)malloc(1 * sizeof(t_cart));
	is_malloc_or_exit(master, map->cart, "Memory allocation, init_map->cart()");
	init_t_cart(map->cart);
	map->iso = (t_iso *)malloc(1 * sizeof(t_iso));
	is_malloc_or_exit(master, map->iso, "Memory allocation, init_map->iso()");
	init_t_iso(map->iso);
	return (map);
}

t_point	*init_point(t_master *master)
{
	t_point	*point;

	point = (t_point *)malloc(1 * sizeof(t_point));
	is_malloc_or_exit(master, point, "Memory allocation, init_point()");
	return (point);
}

void	init_t_cart(t_cart *cart)
{
	cart->x_max = 0;
	cart->x_min = WIN_WIDTH;
	cart->y_max = 0;
	cart->y_min = WIN_HEIGHT;
	cart->x_offset = 0;
	cart->y_offset = 0;
	cart->size = 0;
}

void	init_t_iso(t_iso *iso)
{
	iso->x_max = 0;
	iso->x_min = WIN_WIDTH;
	iso->y_max = 0;
	iso->y_min = WIN_HEIGHT;
	iso->z_fact = 0;
	iso->x_offset = 0;
	iso->y_offset = 0;
	iso->size = 0;
}

void	update_t_cart(t_cart *cart)
{
	cart->x_max = 0;
	cart->x_min = WIN_WIDTH;
	cart->y_max = 0;
	cart->y_min = WIN_HEIGHT;
}

void	update_t_iso(t_iso *iso)
{
	iso->x_max = 0;
	iso->x_min = WIN_WIDTH;
	iso->y_max = 0;
	iso->y_min = WIN_HEIGHT;
	iso->z_fact = 0;
}
