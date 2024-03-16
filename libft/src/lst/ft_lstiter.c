/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:17:46 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:35:52 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lstptr;

	if (!lst)
		return ;
	lstptr = lst;
	while (lstptr)
	{
		f(lstptr->content);
		lstptr = lstptr->next;
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

// void ftest_toupper(void *content)
// {
// 	char *ptr;
// 	int i = 0;

// 	while (content && *(char *)(content + i))
// 	{
// 		ptr = ((char *)content) + i;
// 		if (*ptr >= 'a' && *ptr <= 'z')
// 			*ptr = (*ptr) - 32;
// 		i++;
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	char test0str[] = "first-node!!!";
// 	t_list *test0 = ft_lstnew(test0str);
// 	char test0str1[]= "second-node!!!";
// 	ft_lstadd_back(&test0, ft_lstnew(test0str1));
// 	char test0str2[]= "third-node :DDD";
// 	ft_lstadd_back(&test0, ft_lstnew(test0str2));
// 	printf("lstiter_test0: [\n");
// 		printalist(&test0, 1);
// 	printf("],\n");
// 	ft_lstiter(test0, ftest_toupper);
// 	printf("lstiter_test0-after: [\n");
// 		printalist(&test0, 1);
// 	printf("],\n");

// 	return 0;
// }
