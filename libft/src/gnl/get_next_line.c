/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:31:52 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 05:01:03 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //debug needed by main():
// #include <fcntl.h> //open()
// #include <stdio.h> //printf()

#include "libft.h"
#include <stdlib.h> 	//malloc(), free()
#include <unistd.h>		//read(), main()->close()

char	*splitnl(char **prefix, int i, int suffix_len)
{
	char	*result;
	char	*tmp;

	tmp = NULL;
	while (*prefix && (*prefix)[i + suffix_len])
		suffix_len++;
	if (suffix_len)
	{
		tmp = malloc(suffix_len + 1);
		if (!tmp)
			return (free(*prefix), *prefix = NULL, NULL);
		tmp[suffix_len] = '\0';
		while (suffix_len--)
			tmp[suffix_len] = (*prefix)[i + suffix_len];
	}
	result = malloc(i + 1);
	if (!result)
		return (free(tmp), free(*prefix), *prefix = NULL, NULL);
	result[i] = '\0';
	while (i--)
		result[i] = (*prefix)[i];
	free(*prefix);
	*prefix = tmp;
	return (result);
}

//	returns the next line from file descriptor `fd'.
//	malloc(BUFFER_SIZE*n^2), where n is the amount of recursion it has to do
//		resulted from how big the line is, compared to how small BUFFER_SIZE is.
char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*prefix;
	ssize_t		read_return;
	int			strlen;

	strlen = 0;
	while (prefix && prefix[strlen])
		if (prefix[strlen++] == '\n')
			return (splitnl(&prefix, strlen, 0));
	tmp = malloc(strlen + BUFFER_SIZE + 1);
	if (!tmp)
		return (free(prefix), prefix = NULL, NULL);
	read_return = read(fd, tmp + strlen, BUFFER_SIZE);
	if (read_return < 0)
		return (free(tmp), free(prefix), prefix = NULL, NULL);
	tmp[strlen + read_return] = '\0';
	if (read_return == 0 && (!prefix || !*prefix))
		return (prefix = NULL, free(tmp), NULL);
	while (strlen--)
		tmp[strlen] = prefix[strlen];
	free(prefix);
	prefix = tmp;
	if (read_return == 0)
		return (prefix = NULL, tmp);
	return (get_next_line(fd));
}

////////////////////////////////////////////////////////////////////////////////
//	GET_NEXT_LINE, read() RETURN HANDLING:
//
//  Note that pre always gets copied to tmp.
//
//	Possibilities:		  		Case:	 	do:							return:
//	read_return < 0 && pre;		error: 		pre=NULL, free(pre + tmp),	NULL;
//	read_return < 0 && !pre;	error: 		pre=NULL, free(tmp), 		NULL;
//	read_return == 0 && pre;	EOF: 		pre=NULL, free(pre), 		tmp;
//	read_return == 0 && !pre;	EOF:	 	pre=NULL, free(tmp),		NULL;
////////////////////////////////////////////////////////////////////////////////

// void	*ft_malloc(size_t size)
// {
// 	static int i = 0;

// 	if (i > 3)
// 		return (NULL);
// 	i++;
// 	return (malloc(size));
// }

// int main(int argc, char *argv[])
// {
// 	int		fd = open(argv[1], O_RDONLY);
// 	// int		fd = 3;
// 	// int		fd = 1;
// 	if (fd < 0)
// 		return (1);
// 	char	*hold = NULL;

// 	do
// 	{
// 	 	hold = get_next_line(fd);
// 		if (hold)
// 			printf("%s", hold);
// 		free(hold);
// 	} while (hold);
// 	close(fd);
// 	return (0);
// }
