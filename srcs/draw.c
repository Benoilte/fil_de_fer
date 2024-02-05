/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/05 19:48:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

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
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	master->data_img = img;
	matrix = master->map->matrix;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if ((matrix[y][x])->z != 0)
				my_mlx_pixel_put(img, x, y, 0xFF0000);
			else
				my_mlx_pixel_put(img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(master->mlx->mlx_ptr, master->mlx->win_ptr, img->img, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

// void	display_square(t_vars *vars, int color)
// {
// 	t_data	img;

// 	img.img = mlx_new_image(vars->mlx_ptr, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 					&img.endian);
// 	print_square(&img, 5, 5, color, 100);
// 	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img.img, 0, 0);
// }