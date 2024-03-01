/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/01 12:24:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		close_mlx(fdf);
	else if (key == ARROW_LEFT)
		fdf->camera->x_offset -= 10;
	else if (key == ARROW_UP)
		fdf->camera->y_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	else if (key == ARROW_DOWN)
		fdf->camera->y_offset += 10;
	else if (key == NUM_PAD_PLUS)
		fdf->camera->z_fact++;
	else if (key == NUM_PAD_MINUS)
		fdf->camera->z_fact--;
	else if (key == MAIN_PAD_PGUP)
		zoom(0.1, fdf);
	else if (key == MAIN_PAD_PGDN)
		zoom(-0.1, fdf);
	else if (key == MAIN_PAD_TAB)
		change_color(fdf);
	else
		key_hook_next(key, fdf);
	replace_map(fdf);
	return (0);
}

int	key_hook_next(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_I)
		fdf->camera->projection = 0;
	else if (key == MAIN_PAD_P)
		fdf->camera->projection = 1;
	else if (key == MAIN_PAD_W)
		rotate(fdf, 'x', 3);
	else if (key == MAIN_PAD_S)
		rotate(fdf, 'x', -3);
	if (key == MAIN_PAD_A)
		rotate(fdf, 'y', 3);
	else if (key == MAIN_PAD_D)
		rotate(fdf, 'y', -3);
	else if (key == MAIN_PAD_Y || key == MAIN_PAD_Z)
		rotate(fdf, 'z', 3);
	if (key == MAIN_PAD_X)
		rotate(fdf, 'z', -3);
	else if (key == NUM_PAD_1 || key == NUM_PAD_2 || key == NUM_PAD_3
		|| key == NUM_PAD_4 || key == NUM_PAD_5 || key == NUM_PAD_6)
		view(key, fdf);
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

int	resize_mlx(t_fdf *fdf)
{
	fdf->camera->x_offset = -(fdf->map->x_min);
	fdf->camera->y_offset = -(fdf->map->y_min);
	replace_map(fdf);
	return (0);
}

int	close_mlx(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->img.img);
	mlx_destroy_window(fdf->mlx.mlx_ptr, (fdf->mlx.win_ptr));
	clean_and_exit(fdf, NULL, 0);
	return (0);
}
