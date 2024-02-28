/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:30:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:12:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	***init_matrix(t_fdf *fdf)
{
	t_point	***matrix;
	int		y;
	int		height;
	int		width;

	height = fdf->map->height;
	width = fdf->map->width;
	matrix = (t_point ***)malloc((height + 1) * sizeof(t_point **));
	is_malloc_or_exit(fdf, matrix, "Memory allocation, get_matrix()");
	y = 0;
	while (y <= height)
		matrix[y++] = NULL;
	y = 0;
	while (y < height)
	{
		matrix[y] = (t_point **)malloc((width + 1) * sizeof(t_point *));
		is_malloc_or_exit(fdf, matrix[y], "Memory allocation, get_matrix()");
		init_width_matrix(fdf, matrix[y]);
		y++;
	}
	return (matrix);
}

void	init_width_matrix(t_fdf *fdf, t_point **matrix)
{
	int	x;

	x = 0;
	while (x <= fdf->map->width)
		matrix[x++] = NULL;
	x = 0;
	while (x < fdf->map->width)
		matrix[x++] = init_point(fdf);
}

void	fill_matrix(t_fdf *fdf)
{
	int		x;
	int		y;
	char	**val_tab;
	t_list	*tmp;

	y = 0;
	tmp = fdf->file_lst;
	while (tmp)
	{
		val_tab = ft_split(tmp->content, ' ');
		is_malloc_or_exit(fdf, val_tab, "Memory allocation, fill_matrix()");
		if (check_size_strstr(val_tab) != fdf->map->width)
			clean_and_exit(fdf, "Width of the map are not the same", 1);
		x = 0;
		while ((fdf->map->matrix)[y][x])
		{
			fill_point(fdf, x, y, val_tab[x]);
			get_min_max(fdf, (fdf->map->matrix)[y][x]);
			x++;
		}
		free_strstr(val_tab);
		tmp = tmp->next;
		y++;
	}
}

void	update_matrix(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while ((fdf->map->matrix)[y])
	{
		x = 0;
		while ((fdf->map->matrix)[y][x])
		{
			update_point(fdf, x, y);
			get_min_max(fdf, (fdf->map->matrix)[y][x]);
			x++;
		}
		y++;
	}
}

void	get_min_max(t_fdf *fdf, t_point *point)
{
	if (point->x_proj > fdf->map->x_max)
		fdf->map->x_max = point->x_proj;
	else if (point->x_proj < fdf->map->x_min)
		fdf->map->x_min = point->x_proj;
	if (point->y_proj > fdf->map->y_max)
		fdf->map->y_max = point->y_proj;
	else if (point->y_proj < fdf->map->y_min)
		fdf->map->y_min = point->y_proj;
	if (point->z > fdf->map->z_max)
		fdf->map->z_max = point->z;
	else if (point->z < fdf->map->z_min)
		fdf->map->z_min = point->z;
}
