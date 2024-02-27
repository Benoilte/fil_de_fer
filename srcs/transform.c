/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:28:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/27 12:57:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(double zoom, t_master *master)
{
	if (zoom > 0 || (zoom < 0 && master->map->zoom > 0))
		master->map->zoom += zoom;
	replace_map(master);
}

void	reset_map(t_master *master)
{
	master->map->iso->size = 30;
	master->map->iso->z_fact = 25;
	master->map->zoom = 1;
	master->map->rot_x = 0;
	master->map->rot_y = 0;
	master->map->rot_z = 0;
	update_map(master);
	update_size(master);
	replace_map(master);
}
