/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:32:12 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 03:49:29 by doligtha         ###   ########.fr       */
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
	while (s && n && n--)
		*((char *)s + n) = '\0';
}

// int main()
// {
// 	//string:
// 	int test[200];
// 	int i = -1;
// 	while (++i < 200)
// 	{
// 		test[i] = '\0';
// 		ft_bzero(test, i * sizeof(int));
// 	}
// }
