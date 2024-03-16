/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:08:59 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:40:35 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
#endif

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (s && n--)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

// int main()
// {
// 	size_t i = 0;
// 	char test[10] = "0123456789";
// 	while (i < 11)
// 	{
// 		printf("%s\n", (char *)ft_memset(test, 'a', i));
// 		i++;
// 	}
// 	return (0);
// }
