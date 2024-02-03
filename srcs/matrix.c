/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:30:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 13:44:23 by bebrandt         ###   ########.fr       */
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
	if (!matrix)
		cleanup_and_exit(master, "Memory allocation, get_matrix()", 1);
	y = 0;
	while (y <= height)
		matrix[y++] = NULL;
	y = 0;
	while (y < height)
	{
		matrix[y] = (t_point **)malloc((width + 1) * sizeof(t_point *));
		if (!matrix[y])
			cleanup_and_exit(master, "Memory allocation, get_matrix()", 1);
		else
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
	tmp = master->map_file;
	while (tmp)
	{
		val_tab = ft_split(tmp->content, ' ');
		is_malloc_or_exit(master, val_tab, "Memory allocation, fill_matrix()");
		x = 0;
		while ((master->map->matrix)[y][x])
		{
			fill_point(master, (master->map->matrix)[y][x], val_tab[x]);
			x++;
		}
		free_strstr(val_tab);
		tmp = tmp->next;
		y++;
	}
}
