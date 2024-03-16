/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:50:54 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:49:00 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <bsd/string.h>
#endif

#include <stddef.h>

// this function thinks 'size_t size` is always right. be careful.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	while (src && src[src_len])
		src_len++;
	dst_len = 0;
	while (dst && dst[dst_len])
		dst_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (dst && src && src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst && dst[dst_len + i])
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// void	teststrlcat(char *testnamenumb, size_t result, char *src, char *dst)
// {
// 	printf("%s:\n\t%lu,\n\tdst:\"%s\",\n"
// 	"\tsrc: \"%s\";\n\n", testnamenumb, result, dst, src);
// }

// int main(int argc, char const *argv[])
// {
// 	//command: gcc ft_strlcat.c -lbsd
// 	//NULL:
// 	char *test11dst = "";
// 	char *test11src = "";
// 	size_t test11result = ft_strlcat(test11dst, test11src, 10);
// 	teststrlcat("test11", test11result, test11src, test11dst);

// 	char *test5dst = NULL;
// 	char test5src[] = "6789";
// 	size_t test5result = ft_strlcat(test5dst, test5src, 10);
// 	teststrlcat("test5", test5result, test5src, test5dst);

// 	char test6dst[] = "1234";
// 	char *test6src = NULL;
// 	size_t test6result = ft_strlcat(test6dst, test6src, 10);
// 	teststrlcat("test6", test6result, test6src, test6dst);

// 	char *test7dst = NULL;
// 	char *test7src = NULL;
// 	size_t test7result = ft_strlcat(test7dst, test7src, 10);
// 	teststrlcat("test7", test7result, test7src, test7dst);

// 	//"":
// 	char *test8dst = "";
// 	char test8src[] = "6789";
// 	// fails with size > 1 because dst sometimes = "...\0...\0",
// 	// original strlcat doesn't care so we dont either!
// 	size_t test8result = ft_strlcat(test8dst, test8src, 1);
// 	teststrlcat("test8", test8result, test8src, test8dst);

// 	char test9dst[] = "1234";
// 	char *test9src = "";
// 	size_t test9result = ft_strlcat(test9dst, test9src, 10);
// 	teststrlcat("test9", test9result, test9src, test9dst);

// 	char *test10dst = "";
// 	char *test10src = "";
// 	size_t test10result = ft_strlcat(test10dst, test10src, 10);
// 	teststrlcat("test10", test10result, test10src, test10dst);

// 	return 0;
// }
