/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:07:03 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:42:29 by doligtha         ###   ########.fr       */
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

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (s && i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// int main(int argc, char const *argv[])
// {
// 	char str1[] = "0123456789";
// 	int c = '4';
// 	int i = 0;
// 	// printf("hello world!");
// 	while (i < 12)
// 	{
// 		printf("printing: %s\n", (char *)ft_memchr(str1, c, i));
// 		i++;
// 	}
// 	printf("%s\n", (char *)ft_memchr(str1, '\0', i));
// 	printf("%s\n", (char *)ft_memchr(NULL, c, i));
// 	// printf("%s\n", (char *)ft_memchr(NULL, 0, i));
// 	return 0;
// }
