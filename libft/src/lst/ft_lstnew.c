/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:01:21 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:21:50 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst_it;

	lst_it = (t_list *)malloc(sizeof(t_list));
	if (!lst_it)
		return (NULL);
	lst_it->content = content;
	lst_it->next = NULL;
	return (lst_it);
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
// 		printf("node%d->content=\"%s\",\n", i, (char *)ptr->content);
// 		t = -1;
// 		while (++t < tabs)
// 			printf("\t");
// 		printf("node%d->next=\t%p", i, &ptr->next);
// 		if (ptr->next)
// 			printf(",");
// 		printf("\n\n");
// 		ptr = ptr->next;
// 		i++;
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	printf("lstnew TEST 0: [\n");
// 		t_list	*test0;
// 		test0 = ft_lstnew("");
// 		printalist(&test0, 1);
// 		free(test0->content);
// 	printf("],\n");

// 	printf("lstnew TEST 1: [\n");
// 		t_list	*test1;
// 		test1 = ft_lstnew(NULL);
// 		printalist(&test1, 1);
// 		free(test1->content);
// 	printf("],\n");

// 	printf("lstnew TEST 2: [\n");
// 		t_list	*test2;
// 		test2 = ft_lstnew("0123456789");
// 		printalist(&test2, 1);
// 		free(test2->content);
// 	printf("],\n");

// 	printf("lstnew TEST 3: [\n");
// 		t_list	*test3;
// 		test3 = ft_lstnew("\0");
// 		printalist(&test3, 1);
// 		free(test3->content);
// 	printf("]\n");

// 	return 0;
// }
