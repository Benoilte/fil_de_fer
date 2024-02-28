/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:08:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		close_mlx(fdf);
	else if (key == ARROW_LEFT)
		fdf->map->x_offset -= 10;
	else if (key == ARROW_UP)
		fdf->map->y_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->map->x_offset += 10;
	else if (key == ARROW_DOWN)
		fdf->map->y_offset += 10;
	else if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
		fdf->map->z_fact++;
	else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		fdf->map->z_fact--;
	else if (key == MAIN_PAD_I)
		zoom(0.1, fdf);
	else if (key == MAIN_PAD_O)
		zoom(-0.1, fdf);
	else
		key_hook_next(key, fdf);
	replace_map(fdf);
	return (0);
}

int	key_hook_next(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_D)
		rotate(fdf, 'x', 3.6);
	else if (key == MAIN_PAD_A)
		rotate(fdf, 'x', -3.6);
	if (key == MAIN_PAD_W)
		rotate(fdf, 'y', 3.6);
	else if (key == MAIN_PAD_S)
		rotate(fdf, 'y', -3.6);
	if (key == MAIN_PAD_X)
		rotate(fdf, 'z', 3.6);
	else if (key == MAIN_PAD_Y || key == MAIN_PAD_Z)
		rotate(fdf, 'z', -3.6);
	else if (key == MAIN_PAD_R)
		reset_map(fdf);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_DOWN)
		zoom(0.05, fdf);
	else if (button == MOUSE_SCROLL_UP)
		zoom(-0.05, fdf);
	return (0);
}

int	close_mlx(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->img.img);
	mlx_destroy_window(fdf->mlx.mlx_ptr, (fdf->mlx.win_ptr));
	clean_and_exit(fdf, NULL, 0);
	return (0);
}
