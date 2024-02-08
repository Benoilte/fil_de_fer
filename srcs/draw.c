/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/08 15:39:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_master *master)
{
	t_data	*img;
	int		x;
	int		y;
	t_point	***matrix;

	img = (t_data *)malloc(sizeof(img));
	is_malloc_or_exit(master, img, "Memory allocation, draw_map()");
	img->img = mlx_new_image(master->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	master->data_img = img;
	matrix = master->map->matrix;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			draw_lines(master, x, y);
			// if ((matrix[y][x])->z != 0)
			// 	my_mlx_pixel_put(img,
			// 		(matrix[y][x])->x_iso_dst, (matrix[y][x])->y_iso_dst,
			// 		0xFF0000);
			// else
			// 	my_mlx_pixel_put(img,
			// 		(matrix[y][x])->x_iso_dst, (matrix[y][x])->y_iso_dst,
			// 		0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(master->mlx->mlx_ptr, master->mlx->win_ptr,
		img->img, 0, 0);
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
		draw_line(master->data_img, (matrix[y][x])->x_iso_dst, (matrix[y][x + 1])->x_iso_dst, (matrix[y][x])->y_iso_dst, (matrix[y][x + 1])->y_iso_dst);
	}
	if (y < (height - 1))
	{
		draw_line(master->data_img, (matrix[y][x])->x_iso_dst, (matrix[y + 1][x])->x_iso_dst, (matrix[y][x])->y_iso_dst, (matrix[y + 1][x])->y_iso_dst);
	}
}
/*
Given two points (x1, y1) and (x2, y2) where x1 < x2 and y1 < y2, 
determine the slope of the line m = (y2 - y1) / (x2 - x1).

Initialize variables:

dx = x2 - x1 (change in x)
dy = y2 - y1 (change in y)
d = 2 * dy - dx (initial decision parameter)
For each x-coordinate from x1 to x2:

Plot the pixel at coordinates (x, y).
If the decision parameter d is greater than or equal to 0, 
increment y by 1 and update d = d + 2 * dy.
Otherwise, keep y the same and update d = d + 2 * dy - 2 * dx.
Repeat step 3 until the entire line is drawn.
*/

void	draw_line(t_data *img, int x1, int x2, int y1, int y2)
{
	// int	m;
	int	d;
	int	dx;
	int	dy;

	if (x1 > x2)
		ft_swap(&x1, &x2);
	if (y1 > y2)
		ft_swap(&y1, &y2);
	// m = (y2 - y1) / (x2 - x1);
	dx = x2 - x1;
	dy = y2 - y1;
	d = 2 * dy - dx;
	while (x1 <= x2)
	{
		my_mlx_pixel_put(img, x1, y1, 0xFFFFFF);
		if (d >= 0)
		{
			y1++;
			d += 2 * dy;
		}
		else
			d += 2 * dy - 2 * dx;
		x1++;
	}
}

void	ft_swap(int *n1, int *n2)
{
	int	tmp;

	if (*n1 > *n2)
	{
		tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}
