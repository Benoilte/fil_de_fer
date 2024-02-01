/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 09:02:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
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
		check_file_empty(argv[1]);
		fdf_init(argv[1]);
	}
	return (0);
}

void	fdf_init(char *file)
{
	t_origin_map	*map;

	map = new_map(file);
	ft_printf("height: %d\n", map->height);
	ft_printf("width: %d\n", map->width);
	if (NULL == 0)
		ft_printf("NULL is equal to 0");
	else
		ft_printf("NULL is NOT equal to 0");
	free(map);
}
