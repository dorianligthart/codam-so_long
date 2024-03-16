/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:04:14 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:49:30 by doligtha         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

// int main(void)
// {
// 	printf("%zu\n", ft_strlen(""));
// 	printf("%zu\n", ft_strlen("0"));
// 	printf("%zu\n", ft_strlen("01"));
// 	printf("%zu\n", ft_strlen("012\0"));
// 	printf("%zu\n", ft_strlen(NULL));
// 	printf("%zu\n", ft_strlen("\0"));
// 	return (0);
// }
