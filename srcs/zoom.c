/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:28:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/20 12:51:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_in(int key_code, t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	if (key_code == MOUSE_SCROLL_DOWN)
		master->map->zoom += 0.05;
	else
		master->map->zoom += 0.1;
	update_matrix(master);
	draw_map(master);
}

void	zoom_out(int key_code, t_master *master)
{
	if (master->map->zoom > 0)
	{
		mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
		if (key_code == MOUSE_SCROLL_UP)
			master->map->zoom -= 0.05;
		else
			master->map->zoom -= 0.1;
		update_matrix(master);
		draw_map(master);
	}
}
