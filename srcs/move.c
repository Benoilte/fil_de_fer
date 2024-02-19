/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:32:34 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 18:37:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_left(t_master *master)
{
	master->map->iso->x_offset -= 10;
	draw_map(master);
}

void	move_up(t_master *master)
{
	master->map->iso->y_offset -= 10;
	draw_map(master);
}

void	move_right(t_master *master)
{
	master->map->iso->x_offset += 10;
	draw_map(master);
}

void	move_down(t_master *master)
{
	master->map->iso->y_offset += 10;
	draw_map(master);
}
