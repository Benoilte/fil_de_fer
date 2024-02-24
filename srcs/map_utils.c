/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/24 16:53:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_x_offset(t_master *master)
{
	master->map->iso->x_offset = ((WIN_WIDTH / 2) - master->map->iso->x_min)
		- ((master->map->iso->x_max - master->map->iso->x_min) / 2);
}

void	get_y_offset(t_master *master)
{
	master->map->iso->y_offset = ((WIN_HEIGHT / 2) - master->map->iso->y_min)
		- ((master->map->iso->y_max - master->map->iso->y_min) / 2);
}

void	update_size(t_master *master)
{
	while ((master->map->iso->x_max + master->map->iso->x_offset > WIN_WIDTH
			|| master->map->iso->x_min + master->map->iso->x_offset < 0)
		&& master->map->iso->size > 1)
	{
		master->map->iso->x_max = 0;
		master->map->iso->x_min = WIN_WIDTH;
		master->map->iso->size--;
		update_matrix(master);
		get_x_offset(master);
		get_y_offset(master);
	}
	while ((master->map->iso->y_max + master->map->iso->y_offset > WIN_HEIGHT
			|| master->map->iso->y_min + master->map->iso->y_offset < 0)
		&& master->map->iso->z_fact > 0)
	{
		master->map->iso->y_max = 0;
		master->map->iso->y_min = WIN_HEIGHT;
		master->map->iso->z_fact--;
		update_matrix(master);
		get_x_offset(master);
		get_y_offset(master);
	}
}
