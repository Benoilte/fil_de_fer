/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:47:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/30 18:59:35 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
Exit the program with an error message if the argument is not *.fdf file
*/
void	check_file_name(char *file)
{
	char	*format;

	format = ft_strrchr(file, '.');
	if (format == NULL || ft_strncmp(format, ".fdf", 5))
	{
		ft_printf("file format is not correct\n");
		exit(EXIT_FAILURE);
	}
}

/*
Exit the program with an error message if the file dos not exist
Return fd number if file is open
*/
int	check_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Erorr");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
