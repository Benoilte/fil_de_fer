/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:46:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/20 10:03:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	level_up(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->z_fact++;
	update_matrix(master);
	draw_map(master);
}

void	level_down(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->z_fact--;
	update_matrix(master);
	draw_map(master);
}
