/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:30:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/02 12:16:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	***init_matrix(t_master *master)
{
	t_point	***matrix;
	int		y;

	matrix = (t_point ***)malloc(master->map->height * sizeof(t_point **));
	if (!matrix)
		cleanup_and_exit(master, "Memory allocation, get_matrix()", 1);
	y = 0;
	while (y <= master->map->height)
		matrix[y++] = NULL;
	y = 0;
	while (y < master->map->height)
	{
		matrix[y] = (t_point **)malloc(master->map->width * sizeof(t_point *));
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
	while (matrix[x])
		matrix[x++] = init_point(master);
}

// void	fill_matrix(t_master *master)
// {
// 	int		fd;
// 	int		x;
// 	int		y;
// 	char	*line;
// 	char	**x_tab;

// 	x = 0;
// 	y = 0;
// 	fd = open(master->map_file, O_RDONLY);
// 	while (y < master->map->height)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			cleanup_and_exit(master, "Memory allocation, fill_matrix()", 1);
// 		x_tab = ft_split(line, ' ');
// 		if (!x_tab)
// 			cleanup_and_exit(master, "Memory allocation, fill_matrix()", 1);
// 		while (x < master->map->width)
// 		{
// 			master->map->matrix[y][x] = new_point(x_tab[x]);
// 			x++;
// 		}
// 		free_strstr(x_tab);
// 		free(line);
// 		y++;
// 	}
// 	close(fd);
// }

// void	fill_x_pos