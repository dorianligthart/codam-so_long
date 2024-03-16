/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:11 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:47:03 by doligtha         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*result;
	int		size;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size)
	{
		size--;
		result[size] = s[size];
	}
	return (result);
}

// int main() {
// 	write(1, ft_strdup("0123456789"), 11);
// 	write(1, "\n", 1);
// 	write(1, ft_strdup("012345\0a6789"), 6);
// 	write(1, "\n", 1);
// 	write(1, ft_strdup("\0"), 1);
// 	write(1, "\n", 1);
// 	write(1, ft_strdup(NULL), 1);
// 	write(1, "\n", 1);
// 	write(1, ft_strdup(""), 1);
// 	write(1, "\n", 1);

// 	printf("%s\n", ft_strdup("0123456789"));

// }
