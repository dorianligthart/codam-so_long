/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:14:11 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:45:26 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
#endif

#include <unistd.h>

//	-2147483648 ... 2147483647
void	ft_putnbr_fd(int n, int fd)
{
	long	size;
	char	c;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	size = 1;
	while (size * 10 <= (long)n)
		size = size * 10;
	while (size)
	{
		c = n / size + '0';
		write(fd, &c, 1);
		n = n % size;
		size = size / 10;
	}
}

// int main(int argc, char const *argv[])
// {
// 	int i = 0;

// 	while (++i < 20 && printf("\n"))
// 		ft_putnbr_fd(INT_MAX - 10 + i, 1);
// 	while (i-- && printf("\n"))
// 		ft_putnbr_fd(i - 10, 1);
// 	return 0;
// }
