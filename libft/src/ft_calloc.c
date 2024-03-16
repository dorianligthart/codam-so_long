/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:34:05 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:43:28 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
#endif

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*result;

	total = nmemb * size;
	if (total && total / nmemb != size)
		return (NULL);
	result = (void *)malloc(total);
	if (!result)
		return (NULL);
	while (total--)
		*((char *)result + total) = '\0';
	return (result);
}

// int main(int argc, char const *argv[])
// {
// //	*((char *)result + total) = '\0';
// #if 0
// 	//UINT_MAX = 4294967296
// 	char *test0 = ft_calloc(1, UINT_MAX);
// 	printf("%lu", strlen(test0));
// 	free(test0);
// 
// 	char *test1 = ft_calloc(UINT_MAX, 1);
// 	printf("%lu", strlen(test1));
// 	free(test1);
//  #endif
// 	char *test3 = ft_calloc(0, 0);
// 	printf("%lu", strlen(test3));
// 	free(test3);
// 
// 	char *test4 = ft_calloc(0, 1);
// 	printf("%lu", strlen(test4));
// 	free(test4);
// 
// 	char *test5 = ft_calloc(1, 0);
// 	printf("%lu", strlen(test5));
// 	free(test5);
// 
// 	char *test6 = ft_calloc(1, 1);
// 	printf("%lu", strlen(test6));
// 	free(test6);
// 
// 	char *test7 = ft_calloc(1, 1);
// 	printf("%lu", strlen(test7));
// 	free(test7);
// 
// 	return 0;
// }
