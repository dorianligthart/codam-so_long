/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:26:06 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:44:43 by doligtha         ###   ########.fr       */
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
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;

	result = 0;
	if (!nptr || !*nptr)
		return (0);
	while (*nptr == '\n' || *nptr == '\f' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	i = 0;
	if (*nptr == '-' || *nptr == '+')
		i++;
	while (result <= INT_MAX / 10 && nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	if (nptr[0] == '-')
		result *= -1;
	return (result);
}

// int main (void)
// {
// 	char test_str[] = "      -1";
// 	if (ft_atoi(test_str) != atoi(test_str))
// 		printf("ERROR: with string=%s", test_str);	
// 	char test_str0[] = "      0";
// 	if (ft_atoi(test_str0) != atoi(test_str0))
// 		printf("ERROR: with string=%s", test_str0);
// 	char test_str1[] = "      -2147483649";
// 	if (ft_atoi(test_str1) != atoi(test_str1))
// 		printf("ERROR: with string=%s", test_str1);
// 	char test_str2[] = "      -2147483648";
// 	if (ft_atoi(test_str2) != atoi(test_str2))
// 		printf("ERROR: with string=%s", test_str2);
// 	char test_str3[] = "      2147483648";
// 	if (ft_atoi(test_str3) != atoi(test_str3))
// 		printf("ERROR: with string=%s", test_str3);
// 	char test_str4[] = "      2147483648";
// 	if (ft_atoi(test_str4) != atoi(test_str4))		
// 		printf("ERROR: with string=%s", test_str4);
// 	char test_str5[] = "\t\n\r\v\f  469 \n";
// 	if (ft_atoi(test_str5) != atoi(test_str5))
// 		printf("ERROR: with string=%s", test_str5);
// 	return (0);
// }
