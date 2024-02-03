/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:53:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 14:18:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	is_malloc_or_exit(t_master *master, void *ptr, char *msg)
{
	if (!ptr)
		cleanup_and_exit(master, msg, 1);
}
