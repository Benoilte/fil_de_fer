/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:32:34 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/22 11:08:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_left(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->x_offset -= 10;
	draw_map(master);
}

void	move_up(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->y_offset -= 10;
	draw_map(master);
}

void	move_right(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->x_offset += 10;
	draw_map(master);
}

void	move_down(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->y_offset += 10;
	draw_map(master);
}

void	reset_map(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	master->map->iso->size = get_dist_btwn_iso_point(master);
	master->map->iso->z_fact = master->map->iso->size;
	master->map->zoom = 1;
	master->map->rot_x = 0;
	master->map->rot_y = 0;
	master->map->rot_z = 0;
	update_matrix(master);
	get_x_offset(master);
	get_y_offset(master);
	update_size(master);
	draw_map(master);
}
