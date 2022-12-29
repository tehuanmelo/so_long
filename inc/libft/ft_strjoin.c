/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:24:54 by tde-melo          #+#    #+#             */
/*   Updated: 2022/12/29 18:20:18 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters
//      s1: The prefix string.
//      s2: The suffix string.
// Return value
//      The new string.
//      NULL if the allocation fails.
// External functs.
//      malloc
// Description
//      Allocates (with malloc(3)) and returns a new
//      string, which is the result of the concatenation
//      of ’s1’ and ’s2’.

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	length;
	char	*free_str;
	int		i;

	free_str = s1;
	if (!(s1 && s2))
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((length + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = 0;
	free(free_str);
	return (new);
}

// int main()
// {
//     char *s1 = "hello";
//     char *s2 = "hello";
//     printf("%s\n", ft_strjoin(s1,s2));
// }