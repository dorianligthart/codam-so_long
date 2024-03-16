/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:21:27 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:46:54 by doligtha         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	if (s && (unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

// int main()
// {
// 	write(1, ft_strchr("0123456789", '0'), 10);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '1'), 9);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '2'), 8);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '3'), 7);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '4'), 6);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '4'), 5);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '5'), 5);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '6'), 4);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '7'), 3);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '8'), 2);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", '9'), 1);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("0123456789", 'A'), 16);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr(NULL, 'A'), 16);
// 	write(1, "\n", 1);

// 	write(1, ft_strchr("", 'A'), 16);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("", 0), 16);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("", 0), 0);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr("", 'A'), 0);
// 	write(1, "\n", 1);

// 	write(1, ft_strchr(NULL, 'A'), 16);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr(NULL, 0), 16);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr(NULL, 0), 0);
// 	write(1, "\n", 1);
// 	write(1, ft_strchr(NULL, 'A'), 0);
// 	write(1, "\n", 1);

// 	return (0);	
// }
