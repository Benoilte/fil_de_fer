/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:49:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 14:40:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	cleanup_and_exit(t_master *master, char *msg, int status)
{
	if (master)
	{
		if (master->map_file)
			ft_lstclear(&(master->map_file), &del);
		if (master->map)
			cleanup_map(master->map);
		free(master);
	}
	if (msg)
		ft_printf("Error: %s\n", msg);
	exit (status);
}

void	cleanup_map(t_map *map)
{
	if (map->matrix)
		cleanup_matrix(map->matrix);
	free(map);
}

void	cleanup_matrix(t_point ***matrix)
{
	int	y;
	int	x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			cleanup_point(matrix[y][x]);
			x++;
		}
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	cleanup_point(t_point *point)
{
	free(point);
}
