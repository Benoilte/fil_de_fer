/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/29 13:11:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	***matrix;

	fdf->img.img = mlx_new_image(fdf->mlx.mlx_ptr, WIN_W - MENU_W, WIN_H);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img,
			&fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	matrix = fdf->map->matrix;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			draw_lines(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr,
		fdf->img.img, MENU_W, 0);
}

void	draw_lines(t_fdf *fdf, int x, int y)
{
	t_point	***matrix;
	int		width;
	int		height;

	matrix = fdf->map->matrix;
	width = fdf->map->width;
	height = fdf->map->height;
	if (x < (width - 1))
	{
		ft_bresenham(fdf, matrix[y][x], matrix[y][x + 1]);
	}
	if (y < (height - 1))
	{
		ft_bresenham(fdf, matrix[y][x], matrix[y + 1][x]);
	}
}

/*
m = abs(y2 - y1) / abs(x2 - x1) => m = dy / dx

first case => m < 1 (dx > dy)

second case => m > 1 (dx < dy)
*/
void	ft_bresenham(t_fdf *fdf, t_point *current, t_point *next)
{
	t_bres	val;

	val.x1 = (double)current->x_proj + fdf->camera->x_offset;
	val.x2 = (double)next->x_proj + fdf->camera->x_offset;
	val.y1 = (double)current->y_proj + fdf->camera->y_offset;
	val.y2 = (double)next->y_proj + fdf->camera->y_offset;
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
		slope_first_case(fdf->img, val, current->color, next->color);
	else
		slope_second_case(fdf->img, val, current->color, next->color);
}

void	slope_first_case(t_data img, t_bres val, int col1, int col2)
{
	while (val.i <= val.ex_abs)
	{
		my_mlx_pixel_put(&img, (int)val.x1, (int)val.y1,
			get_color(col1, col2, get_perc(val.y1, val.y2, val.ey)));
		val.i++;
		val.x1 += val.x_rise;
		val.ex -= val.dy;
		if (val.ex < 0.0)
		{
			val.y1 += val.y_rise;
			val.ex += val.dx;
		}
	}
}

void	slope_second_case(t_data img, t_bres val, int col1, int col2)
{
	while (val.i <= val.ey_abs)
	{
		my_mlx_pixel_put(&img, (int)val.x1, (int)val.y1,
			get_color(col1, col2, get_perc(val.x1, val.x2, val.ex)));
		val.i++;
		val.y1 += val.y_rise;
		val.ey -= val.dx;
		if (val.ey < 0.0)
		{
			val.x1 += val.x_rise;
			val.ey += val.dy;
		}
	}
}
