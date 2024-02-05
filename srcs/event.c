/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/05 18:30:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_master *master)
{
	if (key == MAIN_PAD_ESC)
		close_mlx(master);
	return (0);
}

int	close_mlx(t_master *master)
{
	mlx_destroy_window(master->mlx->mlx_ptr, (master->mlx->win_ptr));
	clean_and_exit(master, NULL, 0);
	return (0);
}
