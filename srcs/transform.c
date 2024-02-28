/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:28:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:13:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(double zoom, t_fdf *fdf)
{
	if (zoom > 0 || (zoom < 0 && fdf->map->zoom > 0))
		fdf->map->zoom += zoom;
	replace_map(fdf);
}

void	reset_map(t_fdf *fdf)
{
	fdf->map->size = 30;
	fdf->map->z_fact = 25;
	fdf->map->zoom = 1;
	fdf->map->rot_x = 0;
	fdf->map->rot_y = 0;
	fdf->map->rot_z = 0;
	update_map(fdf);
	update_size(fdf);
	replace_map(fdf);
}
