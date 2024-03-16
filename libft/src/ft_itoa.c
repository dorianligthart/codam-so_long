/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:36:22 by doligtha          #+#    #+#             */
/*   Updated: 2024/02/15 22:24:31 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
#endif

#include "libft.h"
#include <stdlib.h>

//returns length of integer viewed as characters.
static int	ft_itoa_intlen(int n, int base)
{
	int	result;

	result = 1;
	while (n <= -base || n >= base)
	{
		n /= base;
		result++;
	}
	if (n < 0)
		result++;
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		index;
	long	n_long;

	n_long = (long)n;
	index = ft_itoa_intlen(n, 10);
	result = (char *)malloc((index + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[index] = '\0';
	if (n < 0)
		n_long *= -1;
	while (index--)
	{
		result[index] = (n_long % 10) + '0';
		n_long = n_long / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int	main(void)
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	while (i < 20)
// 	{
// 		k = ft_itoa(INT_MAX - 10 + i);
// 		if (!k)
// 			return (-1);
// 		printf("%s\nsize=%d\n", k, sizeof(k));
// 		free(k);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 20)
// 	{
// 		k = ft_itoa(-10 + i);
// 		if (!k)
// 			return (-1);
// 		printf("%s\nsize=%d\n", k, sizeof(k));
// 		free(k);
// 		i++;
// 	}
// 	return (0);
// }
