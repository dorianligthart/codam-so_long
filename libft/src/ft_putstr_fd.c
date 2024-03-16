/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:45:05 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:45:42 by doligtha         ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (s && s[i])
		i++;
	write(fd, s, i);
}

// int main(int argc, char const *argv[])
// {
// 	ft_putstr_fd("", 1);
// 	ft_putstr_fd(NULL, 1);
// 	ft_putstr_fd("0", 1);
// 	ft_putstr_fd("\0", 1);
// 	ft_putstr_fd("abcdefg0123456789", 1);
// 	return 0;
// }
