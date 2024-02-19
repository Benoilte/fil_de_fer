/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:30:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 17:14:08 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	***init_matrix(t_master *master)
{
	t_point	***matrix;
	int		y;
	int		height;
	int		width;

	height = master->map->height;
	width = master->map->width;
	matrix = (t_point ***)malloc((height + 1) * sizeof(t_point **));
	is_malloc_or_exit(master, matrix, "Memory allocation, get_matrix()");
	y = 0;
	while (y <= height)
		matrix[y++] = NULL;
	y = 0;
	while (y < height)
	{
		matrix[y] = (t_point **)malloc((width + 1) * sizeof(t_point *));
		is_malloc_or_exit(master, matrix[y], "Memory allocation, get_matrix()");
		init_width_matrix(master, matrix[y]);
		y++;
	}
	return (matrix);
}

void	init_width_matrix(t_master *master, t_point **matrix)
{
	int	x;

	x = 0;
	while (x <= master->map->width)
		matrix[x++] = NULL;
	x = 0;
	while (x < master->map->width)
		matrix[x++] = init_point(master);
}

void	fill_matrix(t_master *master)
{
	int		x;
	int		y;
	char	**val_tab;
	t_list	*tmp;

	y = 0;
	tmp = master->file_lst;
	while (tmp)
	{
		val_tab = ft_split(tmp->content, ' ');
		is_malloc_or_exit(master, val_tab, "Memory allocation, fill_matrix()");
		if (check_size_strstr(val_tab) != master->map->width)
			clean_and_exit(master, "Width of the map are not the same", 1);
		x = 0;
		while ((master->map->matrix)[y][x])
		{
			fill_point(master, x, y, val_tab[x]);
			get_min_max(master, (master->map->matrix)[y][x]);
			x++;
		}
		free_strstr(val_tab);
		tmp = tmp->next;
		y++;
	}
}

void	update_matrix(t_master *master)
{
	int		x;
	int		y;

	y = 0;
	while ((master->map->matrix)[y])
	{
		x = 0;
		while ((master->map->matrix)[y][x])
		{
			update_point(master, x, y);
			get_min_max(master, (master->map->matrix)[y][x]);
			x++;
		}
		y++;
	}
}

void	get_min_max(t_master *master, t_point *point)
{
	if (point->x_iso_dst > master->map->iso->x_max)
		master->map->iso->x_max = point->x_iso_dst;
	else if (point->x_iso_dst < master->map->iso->x_min)
		master->map->iso->x_min = point->x_iso_dst;
	if (point->y_iso_dst > master->map->iso->y_max)
		master->map->iso->y_max = point->y_iso_dst;
	else if (point->y_iso_dst < master->map->iso->y_min)
		master->map->iso->y_min = point->y_iso_dst;
}
