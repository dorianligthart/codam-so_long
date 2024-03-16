/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:21:30 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/15 23:18:19 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// returns pointer of big where it found little lastly.
char	*ft_strrstr(const char *big, const char *little)
{
	size_t	biglen;
	size_t	len;
	size_t	i;

	biglen = 0;
	while (big && big[biglen])
		biglen++;
	len = 0;
	while (little && little[len])
		len++;
	while (biglen > len && biglen--)
	{
		i = 0;
		while (big[biglen + i] == little[i] && i < len)
			i++;
		if (!little[i])
			return ((char *)(big + biglen));
	}
	return (NULL);
}
