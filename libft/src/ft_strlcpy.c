/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:45:01 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:49:21 by doligtha         ###   ########.fr       */
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

//doesn't concatenate but fills from *dst. doesnt care if size is correct. 
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 0 && src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// void	teststrlcat(char *testnamenumb, size_t result, char *src, char *dst)
// {
// 	printf("%s:\n\t%lu,\n\tdst:\"%s\",\n"
// 	"\tsrc: \"%s\";\n\n", testnamenumb, result, dst, src);
// }

// int main(int argc, char const *argv[])
// {
// 	//command: gcc ft_strlcpy.c -lbsd
// 	//NULL:
// 	char *test5dst = NULL;
// 	char test5src[] = "6789";
// 	size_t test5result = ft_strlcpy(test5dst, test5src, 10);
// 	teststrlcat("test5", test5result, test5src, test5dst);

// 	char test6dst[] = "1234";
// 	char *test6src = NULL;
// 	size_t test6result = ft_strlcpy(test6dst, test6src, 10);
// 	teststrlcat("test6", test6result, test6src, test6dst);

// 	char *test7dst = NULL;
// 	char *test7src = NULL;
// 	size_t test7result = ft_strlcpy(test7dst, test7src, 10);
// 	teststrlcat("test7", test7result, test7src, test7dst);

// 	//"":
// 	char *test8dst = "";
// 	char test8src[] = "6789";
// 	// fails with size > 1 because dst sometimes = "...\0...\0",
// 	// original strlcat doesn't care so we dont either!
// 	size_t test8result = ft_strlcpy(test8dst, test8src, 1);
// 	teststrlcat("test8", test8result, test8src, test8dst);

// 	char test9dst[] = "1234";
// 	char *test9src = "";
// 	size_t test9result = ft_strlcpy(test9dst, test9src, 10);
// 	teststrlcat("test9", test9result, test9src, test9dst);

// 	char *test10dst = "";
// 	char *test10src = "";
// 	size_t test10result = ft_strlcpy(test10dst, test10src, 10);
// 	teststrlcat("test10", test10result, test10src, test10dst);

// 	return 0;
// }
