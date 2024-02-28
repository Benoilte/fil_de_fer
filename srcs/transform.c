/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:28:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:55:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(double zoom, t_fdf *fdf)
{
	if (zoom > 0 || (zoom < 0 && fdf->camera->zoom > 0))
		fdf->camera->zoom += zoom;
	replace_map(fdf);
}

void	reset_map(t_fdf *fdf)
{
	fdf->camera->size = 30;
	fdf->camera->z_fact = 25;
	fdf->camera->zoom = 1;
	fdf->camera->rot_x = 0;
	fdf->camera->rot_y = 0;
	fdf->camera->rot_z = 0;
	update_map(fdf);
	update_size(fdf);
	replace_map(fdf);
}
