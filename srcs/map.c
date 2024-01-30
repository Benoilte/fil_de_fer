/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/30 22:31:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_origin_map	*new_map(char *file)
{
	t_origin_map	*map;

	map = ft_calloc(1, sizeof(t_origin_map *));
	map->height = get_height(file);
	map->width = get_width(file);
	return (map);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;
	char	**coords;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	coords = ft_split(line, ' ');
	width = 0;
	while (coords[width])
		width++;
	free(line);
	free_strstr(coords);
	close(fd);
	return (width);
}

int	get_height(char *file)
{
	int		fd;
	int		height;
	int		check_line;
	char	*line;

	fd = open(file, O_RDONLY);
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
