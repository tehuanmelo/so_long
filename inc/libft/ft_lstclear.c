/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:13:26 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/02 14:09:29 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters
//     lst: The address of a pointer to a node.
//     del: The address of the function used to delete
//     the content of the node.
// Return value
//     None
// External functs.
//     free
// Description
//     Deletes and frees the given node and every
//     successor of that node, using the function ’del’
//     and free(3).
//     Finally, the pointer to the list must be set to
//     NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			*lst = tmp->next;
			del(tmp->content);
			free(tmp);
			tmp = *lst;
		}
	}
}
