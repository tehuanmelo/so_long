/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:24:14 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/02 14:09:06 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters
//     lst: The node to free.
//     del: The address of the function used to delete
//     the content.
// Return value
//     None
// External functs.
//     free
// Description
//     Takes as a parameter a node and frees the memory of
//     the node’s content using the function ’del’ given
//     as a parameter and free the node. The memory of
//     ’next’ must not be freed.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
