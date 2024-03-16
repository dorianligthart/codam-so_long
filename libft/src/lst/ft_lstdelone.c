/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:06:59 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:38:44 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

// void printalist(t_list **start_node, int tabs)
// {
// 	t_list	*ptr;
// 	int 	t;
// 	int		i = 0;

// 	if (!start_node)
// 		return ;
// 	ptr = *start_node;
// 	while (ptr)
// 	{
// 		t = -1;
// 		while (++t < tabs)
// 			printf("\t");
// 		printf("node%d->content=\"%s\"
//	"",\tnode->next%d:%p", i, (char *)ptr->content, i, &ptr->next);
// 		if (ptr->next)
// 			printf(",");
// 		printf("\n");
// 		ptr = ptr->next;
// 		i++;
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	t_list *test0 = ft_lstnew("startnode");
// 	// printf("lstdelone_test0: [\n");
// 	// 	printalist(&test0, 1);
// 	// printf("],\n");
// 	ft_lstdelone(test0, free);
// 	// printf("lstdelone_test0-after: [\n");
// 	// 	printalist(&test0, 1);
// 	// printf("],\n");
// 	return (0);
// }
