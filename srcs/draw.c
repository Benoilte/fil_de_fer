/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 13:24:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_master *master)
{
	int		x;
	int		y;
	t_point	***matrix;

	master->img.img = mlx_new_image(master->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	master->img.addr = mlx_get_data_addr(master->img.img, &master->img.bits_per_pixel,
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
		ft_bresenham(master->img, matrix[y][x], matrix[y][x + 1]);
	}
	if (y < (height - 1))
	{
		ft_bresenham(master->img, matrix[y][x], matrix[y + 1][x]);
	}
}

/*
m = abs(y2 - y1) / abs(x2 - x1) => m = dy / dx

first case => m < 1 (dx > dy)

second case => m > 1 (dx < dy)
*/
void	ft_bresenham(t_data img, t_point *current, t_point *next)
{
	t_bres	val;

	val.x1 = current->x_iso_dst;
	val.x2 = next->x_iso_dst;
	val.y1 = current->y_iso_dst;
	val.y2 = next->y_iso_dst;
	val.x_rise = 1;
	val.y_rise = 1;
	if (val.x1 > val.x2)
		val.x_rise = -1;
	if (val.y1 > val.y2)
		val.y_rise = -1;
	val.ex = abs(val.x2 - val.x1);
	val.ex_abs = val.ex;
	val.ey = abs(val.y2 - val.y1);
	val.ey_abs = val.ey;
	val.dx = 2 * val.ex;
	val.dy = 2 * val.ey;
	val.i = 0;
	if (val.ex_abs > val.ey_abs)
		slope_first_case(img, val, val.x1, val.y1);
	else
		slope_second_case(img, val, val.x1, val.y1);
}

void	slope_first_case(t_data img, t_bres val, int x1, int y1)
{
	while (val.i <= val.ex_abs)
	{
		my_mlx_pixel_put(&img, x1, y1, 0xFFFFFF);
		val.i++;
		x1 += val.x_rise;
		val.ex -= val.dy;
		if (val.ex < 0)
		{
			y1 += val.y_rise;
			val.ex += val.dx;
		}
	}
}

void	slope_second_case(t_data img, t_bres val, int x1, int y1)
{
	while (val.i <= val.ey_abs)
	{
		my_mlx_pixel_put(&img, x1, y1, 0xFFFFFF);
		val.i++;
		y1 += val.y_rise;
		val.ey -= val.dx;
		if (val.ey < 0)
		{
			x1 += val.x_rise;
			val.ey += val.dy;
		}
	}
}
