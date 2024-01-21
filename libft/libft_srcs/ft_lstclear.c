/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:55:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:06:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Deletes and free the memory of the element passed as parameter
and all the following elements
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_el;

	if (!lst)
		return ;
	while (*lst)
	{
		next_el = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_el;
	}
	free(*lst);
	*lst = (void *)0;
}
