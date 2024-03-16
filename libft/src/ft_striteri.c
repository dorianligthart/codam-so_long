/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:49:53 by doligtha          #+#    #+#             */
/*   Updated: 2024/02/16 21:17:18 by doligtha         ###   ########.fr       */
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

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}

// void	iteritest(unsigned int i, char* s)
// {
// 	if (!(i % 2))
// 		*s -= 32;
// }

// int main(int argc, char const *argv[])
// {
// 	char test[] = "abcdefghijklmnopqrstuvwxyz";
// 	ft_striteri(test, iteritest);
// 	printf("%s\n", test);
// 	return 0;
// }
