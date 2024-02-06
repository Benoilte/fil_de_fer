/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/06 18:17:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
parse txt file and return a linked list of struct with a string as member.
*/
t_list	*fill_map_lst(t_master *master)
{
	int		fd;
	int		check_new_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	fd = open_file_or_exit(master);
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
	master->map->height = ft_lstsize(master->file_lst);
	master->map->width = get_width(master);
	master->map->matrix = init_matrix(master);
	master->map->step = 30;
	// master->map->height_offset = ((WIN_HEIGHT / 2) - ((master->map->height * master->map->step) / 2));
	// master->map->width_offset = ((WIN_WIDTH / 2) - ((master->map->width * master->map->step) / 2));
	master->map->height_offset = (WIN_HEIGHT / 2);
	master->map->width_offset = (WIN_WIDTH / 2);
	fill_matrix(master);
}

int	get_width(t_master *master)
{
	int		width;
	char	**coords;

	coords = ft_split(master->file_lst->content, ' ');
	is_malloc_or_exit(master, coords, "Memory allocation, fill_map()");
	width = check_size_strstr(coords);
	free_strstr(coords);
	return (width);
}
