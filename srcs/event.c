/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/20 13:07:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_master *master)
{
	if (key == MAIN_PAD_ESC)
		close_mlx(master);
	else if (key == ARROW_LEFT)
		move_left(master);
	else if (key == ARROW_UP)
		move_up(master);
	else if (key == ARROW_RIGHT)
		move_right(master);
	else if (key == ARROW_DOWN)
		move_down(master);
	else if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
		level_up(master);
	else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		level_down(master);
	else if (key == MAIN_PAD_I)
		zoom_in(key, master);
	else if (key == MAIN_PAD_O)
		zoom_out(key, master);
	else if (key == MAIN_PAD_R)
		reset_map(master);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_master *master)
{

	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_DOWN)
		zoom_in(button, master);
	else if (button == MOUSE_SCROLL_UP)
		zoom_out(button, master);
	return (0);
}

int	close_mlx(t_master *master)
{
	mlx_destroy_image(master->mlx.mlx_ptr, master->img.img);
	mlx_destroy_window(master->mlx.mlx_ptr, (master->mlx.win_ptr));
	clean_and_exit(master, NULL, 0);
	return (0);
}
