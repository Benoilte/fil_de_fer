/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:30:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 13:00:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// t_point	**get_matrix(int height, int width)
// {
// 	t_point	**matrix;
// 	int		i;

// 	matrix = (t_point **)malloc(height * sizeof(t_point *));
// 	if (!matrix)
// 		return (NULL);
// 	i = 0;
// 	while (i < height)
// 	{
// 		*matrix = (t_point *)malloc(width * sizeof(t_point));
// 		if (!*matrix)
// 			return (free_empty_matrix(matrix, i));
// 		i++;
// 	}
// 	return (matrix);
// }

// void	fill_matrix(t_point **matrix, char *file, int h, int w)
// {
// 	int		fd;
// 	int		x;
// 	int		y;
// 	char	*line;
// 	char	**x_tab;

// 	x = 0;
// 	y = 0;
// 	fd = open(file, O_RDONLY);
// 	while (y < h)
// 	{
// 		line = get_next_line(fd);
// 		x_tab = ft_split(line, ' ');
// 		while (x < w)
// 		{
// 			matrix[y][x] = new_point(x_tab[x]);
// 			x++;
// 		}
// 		matrix[y][x] = NULL;
// 		free_strstr(x_tab);
// 		free(line);
// 		y++;
// 	}
// 	close(fd);
// }

// void	fill_x_pos