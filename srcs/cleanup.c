/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:49:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:07:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clean_and_exit(t_fdf *fdf, char *msg, int status)
{
	clean(fdf);
	if (msg)
		ft_printf("Error: %s\n", msg);
	exit (status);
}

void	clean(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->file_lst)
			ft_lstclear(&(fdf->file_lst), &del);
		if (fdf->map)
			clean_map(fdf->map);
		free(fdf);
	}
}

void	clean_map(t_map *map)
{
	if (map->matrix)
		clean_matrix(map->matrix);
	free(map);
}

void	clean_matrix(t_point ***matrix)
{
	int	y;
	int	x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			clean_point(matrix[y][x]);
			x++;
		}
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	clean_point(t_point *point)
{
	free(point);
}
