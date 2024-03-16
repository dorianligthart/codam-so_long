/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:51:12 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:49:47 by doligtha         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if ((s1[i] != s2[i]) || (s1[i] == '\0') || (s2[i] == '\0'))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

// int main(int argc, char const *argv[])
// {
// 	printf("test 1= %d\n", ft_strncmp("", "a", 1));	
// 	printf("test 2= %d\n", ft_strncmp("a", "", 1));	
// 	printf("test 3= %d\n", ft_strncmp("", "", 1));	
// 	printf("test 3.5= %d\n", ft_strncmp("a", "a", 3));	
// 	printf("test 4= %d\n", ft_strncmp(NULL, "a", 3));	
// 	printf("test 5= %d\n", ft_strncmp("a", NULL, 3));	
// 	printf("test 6= %d\n", ft_strncmp(NULL, NULL, 3));	
// 	printf("test 7= %d\n", ft_strncmp("a", "\0", 1));	
// 	printf("test 8= %d\n", ft_strncmp("\0", "", 1));	
// 	printf("test 9= %d\n", ft_strncmp("\0", "\0", 1));
//		
// 	printf("test 10= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 11= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 12= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 13= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 14= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 15= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 16= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 17= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 18= %d\n", ft_strncmp("", "", 3));	
// 	printf("test 19= %d\n", ft_strncmp("", "", 3));	
// 	return 0;
// }
