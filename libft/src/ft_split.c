/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:03:56 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/14 17:31:08 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG 1

#ifdef DEBUG
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
#endif

#include <stdlib.h>

static char	**banana(const char *s, char c, int w, int words)
{
	char	**s2;
	int		i;

	i = 0;
	while (s && s[i])
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			words++;
	s2 = (char **)calloc((words + 1), sizeof(char *));
	while (s2 && i--)
	{
		if (s[i] != c && ++w && (i == 0 || s[i - 1] == c))
		{
			s2[--words] = (char *)malloc((++w) * sizeof(char));
			if (!s2[words])
			{
				while (s2[++words])
					free(s2[words]);
				return (free(s2), NULL);
			}
			s2[words][w - 1] = '\0';
			while (--w)
				s2[words][w - 1] = s[i + w - 1];
		}
	}
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	return (banana(s, c, 0, 0));
}

// int	main(void)
// {	
// 	int i;
// 	// printf("for str=\"%.*s\", w=%d\n", s + i, w);
// 	i = 0;
// 	char **splitted = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	printf("SPLITTEST0: (\"^^^1^^2a,^^^^3^^^^--h^^^^\", '^')\n");
// 	while (splitted && splitted[i])
// 	{
// 		printf("\t'%s'\n", splitted[i]);
// 		free(splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
// 	//
// 	i = 0;
// 	char **splitted0 = ft_split("", '0');	
// 	while (splitted0 && splitted0[i])
// 	{
// 		printf("%s\n", splitted0[i]);
// 		free(splitted0[i]);
// 		i++;
// 	}
// 	free(splitted0);
// 	//
// 	i = 0;
// 	char **splitted1 = ft_split("0", '0');	
// 	while (splitted1 && splitted1[i])
// 	{
// 		printf("%s\n", splitted1[i]);
// 		free(splitted1[i]);
// 		i++;
// 	}
// 	free(splitted1);
// 	//
// 	i = 0;
// 	char **splitted3 = ft_split("A0", '0');
// 	while (splitted3 && splitted3[i])
// 	{
// 		printf("%s\n", splitted3[i]);
// 		free(splitted3[i]);
// 		i++;
// 	}
// 	free(splitted3);
// 	//
// 	i = 0;
// 	char **splitted4 = ft_split("0A", '0');	
// 	while (splitted4 && splitted4[i])
// 	{
// 		printf("%s\n", splitted4[i]);
// 		free(splitted4[i]);
// 		i++;
// 	}
// 	free(splitted4);
// 	// 
// 	i = 0;
// 	char **splitted5 = ft_split("0A0", '0');	
// 	while (splitted5 && splitted5[i])
// 	{
// 		printf("%s\n", splitted5[i]);
// 		free(splitted5[i]);
// 		i++;
// 	}
// 	free(splitted5);
// 	// 
// 	i = 0;
// 	char **splitted2 = ft_split("A", '0');	
// 	while (splitted2 && splitted2[i])
// 	{
// 		printf("%s\n", splitted2[i]);
// 		free(splitted2[i]);
// 		i++;
// 	}
// 	free(splitted2);
// 	// 
// 	i = 0;
// 	char **splitted6 = ft_split("\0", '0');	
// 	while (splitted6 && splitted6[i])
// 	{
// 		printf("%s\n", splitted6[i]);
// 		free(splitted6[i]);
// 		i++;
// 	}
// 	free(splitted6);
// 	// 
// 	i = 0;
// 	char **splitted7 = ft_split("\0", '0');	
// 	while (splitted7 && splitted6[i])
// 	{
// 		printf("%s\n", splitted6[i]);
// 		free(splitted6[i]);
// 		i++;
// 	}
// 	free(splitted6);
// 	//
// 	return (0);
// }
