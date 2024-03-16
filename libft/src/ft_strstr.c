/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:18:04 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/15 23:22:59 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// returns pointer of big where it found little firstly.
char	*ft_strstr(const char *big, const char *little)
{
	size_t	biglen;
	size_t	len;
	size_t	x;
	size_t	y;

	biglen = 0;
	while (big && big[biglen])
		biglen++;
	len = 0;
	while (little && little[len])
		len++;
	if (biglen > len && len > 0)
	{
		y = 0;
		while (y < biglen)
		{
			x = 0;
			while (big[y + x] == little[x] && x < len)
				x++;
			if (!little[x])
				return ((char *)(big + y));
			y++;
		}
	}
	return (NULL);
}
