/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 18:31:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_master *master)
{
	if (key == MAIN_PAD_ESC)
		close_mlx(master);
	if (key == ARROW_LEFT)
		move_left(master);
	if (key == ARROW_UP)
		move_up(master);
	if (key == ARROW_RIGHT)
		move_right(master);
	if (key == ARROW_DOWN)
		move_down(master);
	return (0);
}

int	close_mlx(t_master *master)
{
	// mlx_destroy_image(master->mlx.mlx_ptr, &master->img);
	mlx_destroy_window(master->mlx.mlx_ptr, (master->mlx.win_ptr));
	clean_and_exit(master, NULL, 0);
	return (0);
}
