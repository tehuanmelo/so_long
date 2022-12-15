/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:08:47 by tde-melo          #+#    #+#             */
/*   Updated: 2022/07/15 09:49:23 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//      The ft_memset() function writes len bytes of value c
//      (converted to an unsigned char) to the string b.
// RETURN VALUES
//      The ft_memset() function returns its first argument.

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = c;
	return (b);
}
