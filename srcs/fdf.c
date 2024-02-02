/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/02 18:07:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_master	*master;
	t_list		*map_lst;

	if (argc < 2)
	{
		ft_printf("Error: File is missing\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Error: Too many argument\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		check_file_name(argv[1]);
		check_file_exist(argv[1]);
		map_lst = fill_map_lst(argv[1]);
		display_struct(map_lst);
		check_file_empty(argv[1]);
		master = init_master();
		initialization(master);
		fill_fdf(argv[1], master);
		ft_printf("height: %d\n", master->map->height);
		ft_printf("width: %d\n", master->map->width);
		cleanup_and_exit(master, NULL, 0);
		// run_fdf(master);
	}
	return (0);
}

void	initialization(t_master *master)
{
	master->map = init_map(master);
}

void	fill_fdf(char *file, t_master *master)
{
	master->map_file = file;
	fill_map(master);
}

// void	init_fdf(char *file)
// {
// 	t_fdf	*fdf;
// 	t_map	*map;

// 	map = new_map(file);
// 	ft_printf("height: %d\n", map->height);
// 	ft_printf("width: %d\n", map->width);
// 	free(map);
// }
