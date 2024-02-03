/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:53:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 15:19:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	is_malloc_or_exit(t_master *master, void *ptr, char *msg)
{
	if (!ptr)
		clean_and_exit(master, msg, 1);
}

int		open_file_or_exit(t_master *master)
{
	int	fd;

	fd = open(master->file_name, O_RDONLY);
	if (fd < 0)
	{
		clean(master);
		perror("Erorr");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
