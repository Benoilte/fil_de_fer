/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:53:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:07:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	is_malloc_or_exit(t_fdf *fdf, void *ptr, char *msg)
{
	if (!ptr)
		clean_and_exit(fdf, msg, 1);
}

int	open_file_or_exit(t_fdf *fdf)
{
	int	fd;

	fd = open(fdf->file_name, O_RDONLY);
	if (fd < 0)
	{
		clean(fdf);
		perror("Erorr");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
