/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:49:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 11:45:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clean_and_exit(t_master *master, char *msg, int status)
{
	clean(master);
	if (msg)
		ft_printf("Error: %s\n", msg);
	exit (status);
}

void	clean(t_master *master)
{
	if (master)
	{
		if (master->file_lst)
			ft_lstclear(&(master->file_lst), &del);
		if (master->map)
			clean_map(master->map);
		if (master->mlx)
			free(master->mlx);
		if (master->data_img)
			free(master->data_img);
		free(master);
	}
}

void	clean_map(t_map *map)
{
	if (map->cart)
		free(map->cart);
	if (map->iso)
		free(map->iso);
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
