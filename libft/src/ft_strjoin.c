/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:50:58 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:47:50 by doligtha         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	s1_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2 && s2[s2_len])
		s2_len++;
	result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[s1_len + s2_len] = '\0';
	while (s2 && s2_len--)
		result[s1_len + s2_len] = s2[s2_len];
	while (s1 && s1_len--)
		result[s1_len] = s1[s1_len];
	return (result);
}

// int main(int argc, char const *argv[])
// {
// 	char test1[] = "0123456789";
// 	char test2[] = "abcdefghij";
// 	char *ult;

// 	ult = ft_strjoin(test1, test2);
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin(NULL, test2);
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin(test1, NULL);
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin(NULL, NULL);
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin(test1, "");
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin("", test2);
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin("", "");
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin(test1, "a");
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin("A", test2);
// 	printf("%s\n", ult);
// 	free(ult);
// 	ult = ft_strjoin("A", "a");
// 	printf("%s\n", ult);
// 	free(ult);
// 	return 0;
// }
