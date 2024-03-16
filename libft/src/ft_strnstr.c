/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:51:15 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:49:54 by doligtha         ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	big_len;

	if (!little || !*little)
		return ((char *)big);
	big_len = 0;
	while (big && big[big_len])
		big_len++;
	if (len > big_len)
		len = big_len;
	i = 0;
	while (big && little && big[i] && i < len)
	{
		k = 0;
		while (i + k < len
			&& big[i + k] && little[k] && big[i + k] == little[k])
			k++;
		if (!little[k])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int main(int argc, char const *argv[])
// {
// 	printf("test0: [\n");
// 		char test0big[] = "0123456789";
// 		char test0little[] = "9";
// 		char *test0result;
// 		size_t i = 0;
// 		while (i < 12)
// 		{
// 			test0result = ft_strnstr(test0big, test0little, i);
// 			printf("\tlen=%zu: \"%s\"\n", i, test0result);
// 			i++;
// 		}
// 	printf("],\n");
// 	printf("test1: [\n");
// 		char test1big[] = "0123456789";
// 		char test1little[] = "0123";
// 		char *test1result;
// 		i = 0;
// 		while (i < 12)
// 		{
// 			test1result = ft_strnstr(test1big, test1little, i);
// 			printf("\tlen=%zu: \"%s\"\n", i, test1result);
// 			i++;
// 		}
// 	printf("],\n");
// 	printf("test2: [\n");
// 		char test2big[] = "01234560a89";
// 		char test2little[] = "0a";
// 		char *test2result;
// 		i = 0;
// 		while (i < 12)
// 		{
// 			test2result = ft_strnstr(test2big, test2little, i);
// 			printf("\tlen=%zu: \"%s\"\n", i, test2result);
// 			i++;
// 		}
// 	printf("],\n");
// 	printf("test3: [\n");
// 		char test3big[] = "012345012345a";
// 		char test3little[] = "012345a";
// 		char *test3result;
// 		i = 0;
// 		while (i < 14)
// 		{
// 			test3result = ft_strnstr(test3big, test3little, i);
// 			printf("\tlen=%zu: \"%s\"\n", i, test3result);
// 			i++;
// 		}
// 	printf("],\n");
// 	printf("test4: [\n");
// 		char test4big[] = "0__0a_0ab_";
// 		char test4little[] = "0ab";
// 		char *test4result;
// 		i = 0;
// 		while (i < 12)
// 		{
// 			test4result = ft_strnstr(test4big, test4little, i);
// 			printf("\tlen=%zu: \"%s\"\n", i, test4result);
// 			i++;
// 		}
// 	printf("],\n");

// 	//NULL:
// 	printf("test5: [\n");
// 		char *test5big = NULL;
// 		char test5little[] = "6789";
// 		char *test5result;
// 		test5result = ft_strnstr(test5big, test5little, 10);
// 		printf("\t\"%s\"\n", test5result);
// 	printf("],\n");
// 	printf("test6: [\n");
// 		char test6big[] = "1234";
// 		char *test6little = NULL;
// 		char *test6result;
// 		test6result = ft_strnstr(test6big, test6little, 10);
// 		printf("\t\"%s\"\n", test6result);
// 	printf("],\n");
// 	printf("test7: [\n");
// 		char *test7big = NULL;
// 		char *test7little = NULL;
// 		char *test7result;
// 		test7result = ft_strnstr(test7big, test7little, 10);
// 		printf("\t\"%s\"\n", test7result);
// 	printf("],\n");

// 	//"":
// 	printf("test8: [\n");
// 		char *test8big = "";
// 		char test8little[] = "6789";
// 		char *test8result;
// 		test8result = ft_strnstr(test8big, test8little, 10);
// 		printf("\t\"%s\"\n", test8result);
// 	printf("],\n");
// 	printf("test9: [\n");
// 		char test9big[] = "1234";
// 		char *test9little = "";
// 		char *test9result;
// 		test9result = ft_strnstr(test9big, test9little, 10);
// 		printf("\t\"%s\"\n", test9result);
// 	printf("],\n");
// 	printf("test10: [\n");
// 		char *test10big = "";
// 		char *test10little = "";
// 		char *test10result;
// 		test10result = ft_strnstr(test10big, test10little, 10);
// 		printf("\t\"%s\"\n", test10result);
// 	printf("],\n");

// 	return 0;
// }
