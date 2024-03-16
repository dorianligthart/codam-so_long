/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:33:20 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 20:17:59 by doligtha         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;

	s_len = 0;
	while (s && s[s_len])
		s_len++;
	if (start > s_len)
		start = s_len;
	if (len > s_len - start || start + len > s_len)
		len = s_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
		result[len] = s[start + len];
	return (result);
}

// int main(int argc, char const *argv[])
// {
// 	char *test0src = NULL;
// 	char *test0dest = ft_substr(test0src, 0, 20);
// 	printf("test0: \'%s\',\n",   test0dest);
// 	free(test0dest);

// 	char *test1src = {0};
// 	char *test1dest = ft_substr(test1src, 0, 20);
// 	printf("test1: \'%s\',\n",  test1dest);
// 	free(test1dest);

// 	char test1p5src[] = {0};
// 	char *test1p5dest = ft_substr(test1p5src, 0, 20);
// 	printf("test1p5: \'%s\',\n",  test1p5dest);
// 	free(test1p5dest);

// 	char  test2src[] = "";
// 	char *test2dest = ft_substr(test2src, 0, 20);
// 	printf("test2: \'%s\',\n",  test2dest);
// 	free(test2dest);

// 	char  test3src[] = "0123456789";
// 	char *test3dest = ft_substr(test3src, 0, 20);
// 	printf("test3: \'%s\',\n\n",  test3dest);
// 	free(test3dest);

// 	int i = 0;
// //	char  test4src[] = "0123456789";
// //	while (i < 11)
// //	{
// //		char *test4dest = ft_substr(test4src, 0, i);	
// //		printf("\ttest4: \'%s\',\n",  test4dest);
// //		i++;
// //		free(test4dest );
// //	}
// //	printf("\n");
// //
// //	i = 0;
// //	char  test5src[] = "0123456789";
// //	while (i < 11)
// //	{
// //		char *test5dest = ft_substr(test5src, i, 20);	
// //		printf("\ttest5: \'%s\',\n",  test5dest);
// //		i++;
// //		free(test5dest );
// //	}
// //	printf("\n");

// 	//edge cases near 0 and strlen:
// 	char  test6src[] = "0123456789";
// 	char *test6dest = ft_substr(test6src, 1, 1);
// 	printf("test6: \'%s\',\n\n",  test6dest);
// 	free(test6dest);

// 	char  test7src[] = "0123456789";
// 	char *test7dest = ft_substr(test7src, 1, 2);
// 	printf("test7: \'%s\',\n\n",  test7dest);
// 	free(test7dest);

// 	char  test8src[] = "0123456789";
// 	char *test8dest = ft_substr(test8src, 8, 9);
// 	printf("test8: \'%s\',\n\n",  test8dest);
// 	free(test8dest);

// 	char  test9src[] = "0123456789";
// 	char *test9dest = ft_substr(test9src, 9, 9);
// 	printf("test9: \'%s\',\n\n",  test9dest);
// 	free(test9dest);

// 	char  test10src[] = "0123456789";
// 	char *test10dest = ft_substr(test10src, 9, 10);
// 	printf("test10: len%lu, \"", strlen(test0dest));
// 	fwrite(test10dest, sizeof(char), (size_t)2, stdout);
// 	printf("\"\n");
// 	free(test10dest);

// 	return 0;
// }
