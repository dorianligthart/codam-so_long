/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:16:02 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:41:50 by doligtha         ###   ########.fr       */
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest && src && dest < src && i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	while (dest && src && dest >= src && n--)
		*(char *)(dest + n) = *(char *)(src + n);
	return (dest);
}

// int main(int argc, char const *argv[])
// {
// 	char str1[] = "0123456789";
// 	char str2[] = "abcdef";
// 	int i = 0;

// 	while (i < 12)
// 	{
// 		printf("%s\n", (char *)ft_memmove(str1, str2, i));
// 		i++;
// 	}	
// 	char *str3 = "0123456789";
// 	char *str4 = "abcdef";
// 	printf("%s\n", (char *)ft_memmove(NULL, str4, i));
// 	printf("%s\n", (char *)ft_memmove(str3, str4, i));
// 	printf("%s\n", (char *)ft_memmove(str3, NULL, i));
// 	char *str6 = "0123456789";
// 	char *str5 = "abcdef";
// 	printf("%s\n", (char *)ft_memmove(str5, str6, i));
// 	printf("%s\n", (char *)ft_memmove(str5, NULL, i));
// 	printf("%s\n", (char *)ft_memmove(NULL, NULL, i));
// 	return 0;
// }
