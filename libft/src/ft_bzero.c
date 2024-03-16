/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:32:12 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:44:17 by doligtha         ###   ########.fr       */
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

void	ft_bzero(void *s, size_t n)
{
	while (s && n--)
		((unsigned char *)s)[n] = '\0';
}

// int main()
// {
// 	//string:
// 	char *test;
// 	int i = 0;
// 	while (i <  200)
// 	{
// 		test = malloc(i + 1);
// 		test[i] = '\0';
// 		test = ft_bzero((void *)s, i);
// 		printf("%d:\n%s\n", i, test);
// 		free(test);
// 	}
// }
