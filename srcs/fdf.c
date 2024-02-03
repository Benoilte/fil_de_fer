/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 15:28:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_master	*master;

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
		master = init_master(argv[1]);
		initialization(master);
		check_file_empty(master);
		fill_fdf(master);
		ft_print_matrix(master->map->matrix);
		ft_printf("height: %d\n", master->map->height);
		ft_printf("width: %d\n", master->map->width);
		clean(master);
	}
	return (0);
}

void	initialization(t_master *master)
{
	master->file_lst = fill_map_lst(master);
	display_struct(master->file_lst);
	master->map = init_map(master);
}

void	fill_fdf(t_master *master)
{
	fill_map(master);
}
