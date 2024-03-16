/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:30:34 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:42:07 by doligtha         ###   ########.fr       */
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 && s2)
		return (*(unsigned char *)(s2) * -1);
	if (s1 && !s2)
		return (*(unsigned char *)(s1));
	if (n == 0 || (!s1 && !s2))
		return (0);
	i = 0;
	while (--n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

// int	main()
// {
// 	int i = 0;
// 	char *str1 = "012345689";
// 	char *str2 = "012345689c";
// 	while (i < 11)
// 	{
// 		printf("%d\n", ft_memcmp(str1, str2, i));
// 		i++;
// 	}
// 	printf("%d\n", ft_memcmp(NULL, str2, i));
// 	printf("%d\n", ft_memcmp(str1, NULL, i));
// 	printf("%d\n", ft_memcmp(NULL, NULL, i));
// 	return (0);
// }
