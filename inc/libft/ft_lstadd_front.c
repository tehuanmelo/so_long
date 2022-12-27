/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:32:20 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/07/29 15:11:09 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
**     lst:
**         The address of a pointer to the first link of
**         a list.
**     new:
**         The address of a pointer to the node to be
**         added to the list.
** Return value
**     None
** External functs.
**     None
** Description
**     Adds the node ’new’ at the beginning of the list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(lst || new))
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

// int main()
// {

//     t_list *new = ft_lstnew("world");
//     t_list *lst = NULL;

//     ft_lstadd_front(&lst, new);
//     ft_lstadd_back(&lst, ft_lstnew("hello"));

//     printf("%s\n", (char*)lst->next->content);
// }