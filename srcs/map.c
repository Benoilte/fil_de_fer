/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 13:46:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
parse txt file and return a linked list of struct with a string as member.
*/
t_list	*fill_map_lst(char *file)
{
	int		fd;
	int		check_new_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			check_new_line = 0;
			if (ft_strchr(line, '\n'))
				check_new_line = 1;
			str = ft_substr(line, 0, ft_strlen(line) - check_new_line);
			ft_lstadd_back(&input, ft_lstnew(str));
		}
		else
			break ;
		free(line);
	}
	close(fd);
	return (input);
}

void	fill_map(t_master *master)
{
	master->map->height = ft_lstsize(master->map_file);
	master->map->width = get_width(master);
	master->map->matrix = init_matrix(master);
	fill_matrix(master);
}

int	get_width(t_master *master)
{
	int		width;
	char	**coords;

	coords = ft_split(master->map_file->content, ' ');
	if (!coords)
		cleanup_and_exit(master, "Memory allocation, fill_map()", 1);
	width = 0;
	while (coords[width])
		width++;
	free_strstr(coords);
	return (width);
}

// int	get_height(t_master *master)
// {
// 	int		fd;
// 	int		height;
// 	int		check_line;
// 	char	*line;

// 	fd = open(master->map_file, O_RDONLY);
// 	height = 0;
// 	check_line = 1;
// 	while (check_line)
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 			height++;
// 		else
// 			check_line = 0;
// 		free(line);
// 	}
// 	close(fd);
// 	return (height);
// }
