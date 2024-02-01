/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 15:19:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_map(t_master *master)
{
	master->map->height = get_height(master);
	master->map->width = get_width(master);
	master->map->matrix = init_matrix(master);
}

int	get_width(t_master *master)
{
	int		fd;
	int		width;
	char	*line;
	char	**coords;

	fd = open(master->map_file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		cleanup_and_exit(master, "Memory allocation, fill_map()", 1);
	coords = ft_split(line, ' ');
	if (!coords)
		cleanup_and_exit(master, "Memory allocation, fill_map()", 1);
	width = 0;
	while (coords[width])
		width++;
	free(line);
	free_strstr(coords);
	close(fd);
	return (width);
}

int	get_height(t_master *master)
{
	int		fd;
	int		height;
	int		check_line;
	char	*line;

	fd = open(master->map_file, O_RDONLY);
	height = 0;
	check_line = 1;
	while (check_line)
	{
		line = get_next_line(fd);
		if (line)
			height++;
		else
			check_line = 0;
		free(line);
	}
	close(fd);
	return (height);
}
