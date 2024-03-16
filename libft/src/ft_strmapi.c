/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:51:09 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:49:39 by doligtha         ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		s_len;

	s_len = 0;
	while (s && s[s_len])
		s_len++;
	result = (char *)malloc((s_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[s_len] = '\0';
	while (s_len--)
		result[s_len] = (*f)(s_len, s[s_len]);
	return (result);
}
// char	mapiUPCASE(unsigned int i, char c)
// {
// 	if (!(i % 1))
// 		c -= 32;
// 	return (c);
// }

// int main(int argc, char const *argv[])
// {
// 	char test[] = "abcdefghijklmnopqrstuvwxyz";
// 	char *ret;

// 	ret =  ft_strmapi(test, mapiUPCASE);
// 	printf("%s\n", ret);
// 	free(ret);
// 	return 0;
// }
