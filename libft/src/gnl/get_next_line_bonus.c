/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:31:52 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 05:01:14 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 	//ft_malloc, free
#include <unistd.h>		//read

//	returns the next line from file descriptor `fd'. 
//	sizeof(char *) = 8, 8 * 1024 = 8192 bytes on static variable memory.
//	malloc(BUFFER_SIZE*n^2), where n is the amount of recursion it has to do
//		resulted from how big the line is, compared to how small BUFFER_SIZE is.
char	*get_next_line_bon(int fd)
{
	char		*result;
	static char	*prefix[1024];
	int			strlen;
	int			read_return;

	if (fd <= 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	read_return = 1;
	while (read_return)
	{
		strlen = 0;
		while (prefix[fd] && prefix[fd][strlen])
			if (prefix[fd][strlen++] == '\n')
				return (gnl_splitnl(&(prefix[fd]), strlen, NULL));
		result = malloc(strlen + BUFFER_SIZE + 1);
		if (!result)
			return (free(prefix[fd]), prefix[fd] = NULL, NULL);
		read_return = read(fd, result + strlen, BUFFER_SIZE);
		if (read_return < 0)
			return (free(result), free(prefix[fd]), prefix[fd] = NULL, NULL);
		result[strlen + read_return] = '\0';
		while (strlen--)
			result[strlen] = prefix[fd][strlen];
		free(prefix[fd]);
		prefix[fd] = NULL;
		prefix[fd] = result;
	}
	return (result);
}
