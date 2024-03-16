/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:22:42 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:54:23 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
#endif

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	begin;
	size_t	mid;
	size_t	end;

	begin = 0;
	mid = 0;
	end = 0;
	while (s1 && s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (s1 && s1[begin + mid])
		mid++;
	while (s1 && s1[begin] && ft_strchr(set, s1[begin + mid - 1 - end]))
		end++;
	mid = mid - end;
	result = malloc(mid + 1);
	if (!result)
		return (NULL);
	result[mid] = '\0';
	while (mid--)
		result[mid] = s1[begin + mid];
	return (result);
}

// int main(int argc, char const *argv[])
// {
// 	char *test0  = ft_strtrim("abc", "");
// 	printf("nullcheck:\n%s\n", test0);
// 	free(test0);
// 	//
// 	char *test1  = ft_strtrim("", "abc");
// 	printf("%s\n", test1);
// 	free(test1);
// 	//
// 	char *test2  = ft_strtrim("", "");
// 	printf("%s\n", test2);
// 	free(test2);
// 	//
// 	char *test3  = ft_strtrim("ABC", NULL);
// 	printf("%s\n", test3);
// 	free(test3);
// 	//
// 	char *test4  = ft_strtrim(NULL, "ABC");
// 	printf("%s\n", test4);
// 	free(test4);
// 	//
// 	char *test5  = ft_strtrim(NULL, NULL);
// 	printf("%s\n", test5);
// 	free(test5);
// 	//
// 	char *test6  = ft_strtrim("abc", "b");
// 	printf("non-nullcheck:\n%s\n", test6);
// 	free(test6);
// 	//
// 	char *test7  = ft_strtrim("ab", "a");
// 	printf("%s\n", test7);
// 	free(test7);
// 	//
// 	char *test8  = ft_strtrim("bc", "c");
// 	printf("%s\n", test8);
// 	free(test8);
// 	//
// 	char *test9  = ft_strtrim("abc", "ac");
// 	printf("%s\n", test9);
// 	free(test9);
// 	//
// 	char *test10 = ft_strtrim("aaaaaaabcccccc", "ac");
// 	printf("%s\n", test10);
// 	free(test10);
// 	//
// 	char *test11 = ft_strtrim("aaaccc", "ac");
// 	printf("%s\n", test11);
// 	free(test11);
// 	//
// 	char *test12 = ft_strtrim("aaabbbccc", "ac");
// 	printf("%s\n", test12);
// 	free(test12);
// 	char *test13 = ft_strtrim("a", "a");
// 	printf("%s\n", test13);
// 	free(test13);
// 	return 0;
// }
