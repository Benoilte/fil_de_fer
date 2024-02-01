/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:21:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 14:57:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_master	*init_master(void)
{
	t_master	*master;

	master = (t_master *)malloc(1 * sizeof(t_master));
	if (!master)
		cleanup_and_exit(master, "Memory allocation, function init_master", 1);
	master->map_file = NULL;
	master->map = NULL;
	return (master);
}

t_map	*init_map(t_master *master)
{
	t_map	*map;

	map = (t_map *)malloc(1 * sizeof(t_map));
	if (!map)
		cleanup_and_exit(master, "Memory allocation, function init_map", 1);
	map->matrix = NULL;
	return (map);
}
