/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/24 14:26:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_master *master)
{
	int		x;
	int		y;
	t_point	***matrix;

	master->img.img = mlx_new_image(master->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	master->img.addr = mlx_get_data_addr(master->img.img,
			&master->img.bits_per_pixel,
			&master->img.line_length, &master->img.endian);
	matrix = master->map->matrix;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			draw_lines(master, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(master->mlx.mlx_ptr, master->mlx.win_ptr,
		master->img.img, 0, 0);
}

void	draw_lines(t_master *master, int x, int y)
{
	t_point	***matrix;
	int		width;
	int		height;

	matrix = master->map->matrix;
	width = master->map->width;
	height = master->map->height;
	if (x < (width - 1))
	{
		ft_bresenham(master, matrix[y][x], matrix[y][x + 1]);
	}
	if (y < (height - 1))
	{
		ft_bresenham(master, matrix[y][x], matrix[y + 1][x]);
	}
}

/*
m = abs(y2 - y1) / abs(x2 - x1) => m = dy / dx

first case => m < 1 (dx > dy)

second case => m > 1 (dx < dy)
*/
void	ft_bresenham(t_master *master, t_point *current, t_point *next)
{
	t_bres	val;

	val.x1 = (double)current->x_iso_dst + master->map->iso->x_offset;
	val.x2 = (double)next->x_iso_dst + master->map->iso->x_offset;
	val.y1 = (double)current->y_iso_dst + master->map->iso->y_offset;
	val.y2 = (double)next->y_iso_dst + master->map->iso->y_offset;
	val.x_rise = 1.0;
	val.y_rise = 1.0;
	if (val.x1 > val.x2)
		val.x_rise = -1.0;
	if (val.y1 > val.y2)
		val.y_rise = -1.0;
	val.ex = fabs(val.x2 - val.x1);
	val.ex_abs = val.ex;
	val.ey = fabs(val.y2 - val.y1);
	val.ey_abs = val.ey;
	val.dx = 2 * val.ex;
	val.dy = 2 * val.ey;
	val.i = 0.0;
	if (val.ex_abs > val.ey_abs)
		slope_first_case(master->img, val, val.x1, val.y1);
	else
		slope_second_case(master->img, val, val.x1, val.y1);
}

void	slope_first_case(t_data img, t_bres val, double x1, double y1)
{
	while (val.i <= val.ex_abs)
	{
		my_mlx_pixel_put(&img, x1, y1,
			get_color(0x4A235A, 0xF1C40F, get_perc(y1, val.y2, val.ey)));
		val.i++;
		x1 += val.x_rise;
		val.ex -= val.dy;
		if (val.ex < 0.0)
		{
			y1 += val.y_rise;
			val.ex += val.dx;
		}
	}
}

void	slope_second_case(t_data img, t_bres val, double x1, double y1)
{
	while (val.i <= val.ey_abs)
	{
		my_mlx_pixel_put(&img, x1, y1,
			get_color(0x4A235A, 0xF1C40F, get_perc(x1, val.x2, val.ex)));
		val.i++;
		y1 += val.y_rise;
		val.ey -= val.dx;
		if (val.ey < 0.0)
		{
			x1 += val.x_rise;
			val.ey += val.dy;
		}
	}
}
