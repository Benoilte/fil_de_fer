/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/27 12:52:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_master *master)
{
	if (key == MAIN_PAD_ESC)
		close_mlx(master);
	else if (key == ARROW_LEFT)
		master->map->iso->x_offset -= 10;
	else if (key == ARROW_UP)
		master->map->iso->y_offset -= 10;
	else if (key == ARROW_RIGHT)
		master->map->iso->x_offset += 10;
	else if (key == ARROW_DOWN)
		master->map->iso->y_offset += 10;
	else if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
		master->map->iso->z_fact++;
	else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		master->map->iso->z_fact--;
	else if (key == MAIN_PAD_I)
		zoom(0.1, master);
	else if (key == MAIN_PAD_O)
		zoom(-0.1, master);
	else
		key_hook_next(key, master);
	replace_map(master);
	return (0);
}

int	key_hook_next(int key, t_master *master)
{
	if (key == MAIN_PAD_D)
		rotate(master, 'x', 3.6);
	else if (key == MAIN_PAD_A)
		rotate(master, 'x', -3.6);
	if (key == MAIN_PAD_W)
		rotate(master, 'y', 3.6);
	else if (key == MAIN_PAD_S)
		rotate(master, 'y', -3.6);
	if (key == MAIN_PAD_X)
		rotate(master, 'z', 3.6);
	else if (key == MAIN_PAD_Y || key == MAIN_PAD_Z)
		rotate(master, 'z', -3.6);
	else if (key == MAIN_PAD_R)
		reset_map(master);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_master *master)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_DOWN)
		zoom(0.05, master);
	else if (button == MOUSE_SCROLL_UP)
		zoom(-0.05, master);
	return (0);
}

int	close_mlx(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	mlx_destroy_window(master->mlx.mlx_ptr, (master->mlx.win_ptr));
	clean_and_exit(master, NULL, 0);
	return (0);
}
