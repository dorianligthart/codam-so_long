/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:23:14 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:40:01 by doligtha         ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	if (s && *s)
	{
		i = 0;
		while (s && s[i])
			i++;
		write(fd, s, i);
	}
	write(fd, "\n", 1);
}

// int main(int argc, char const *argv[])
// {
// 	ft_putendl_fd("", 1);
// 	ft_putendl_fd(NULL, 1);
// 	ft_putendl_fd("0", 1);
// 	ft_putendl_fd("\0", 1);
// 	ft_putendl_fd("abcdefg0123456789", 1);
// 	return 0;
// }
