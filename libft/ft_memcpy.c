/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:28:01 by tde-melo          #+#    #+#             */
/*   Updated: 2022/07/21 13:40:58 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//      The ft_memcpy() function copies n bytes from memory area src to memory
//      area dst. If dst and src overlap, behavior is undefined.
//      Applications in which dst and src might overlap should use memmove(3)
//      instead.
// RETURN VALUES
//      The ft_memcpy() function returns the original value of dst.

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// int main()
// {
// 	char str[] = "abcdef";
// 	printf("%s\n", (char *)ft_memcpy(str + 2, str, 4)-2);
// }