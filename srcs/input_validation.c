/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:47:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/30 22:37:14 by bebrandt         ###   ########.fr       */
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
*/
void	check_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Erorr");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

/*
Exit the program with an error message if the file is empty
*/
void	check_file_empty(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Erorr: file is empty\n");
		exit(EXIT_FAILURE);
	}
	free(line);
	close(fd);
}
