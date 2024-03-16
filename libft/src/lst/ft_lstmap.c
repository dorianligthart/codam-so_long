/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:25:28 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:36:10 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*ptr;

	new_list = NULL;
	while (lst && f && del)
	{
		ptr = f(lst->content);
		if (!ptr)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = ft_lstnew(ptr);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			del(ptr);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
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
// 	//=========//
// 	// TEST_0: //
// 	char test0str[] = "first-node!!!";
// 	t_list *test0 = ft_lstnew(test0str);
// 	char test0str1[]= "second-node!!!";
// 	ft_lstadd_back(&test0, ft_lstnew(test0str1));
// 	char test0str2[]= "third-node :DDD";
// 	//
// 	ft_lstadd_back(&test0, ft_lstnew(test0str2));
// 		printf("lstiter_test0: [\n");
// 			printalist(&test0, 1);
// 		printf("],\n");
// 	//
// 	t_list *result0 = ft_lstmap(test0, ftest_toupper, free);
// 		printf("lstiter_test0-after: [\n");
// 			printalist(&test0, 1);
// 		printf("],\n");
// 	//
// 	ft_lstclear(&test0, free);
// 	ft_lstclear(&result0, free);
// 	//=========//
// 	// TEST_1: //
// 	char test1str[] = "";
// 	t_list *test1 = ft_lstnew(test1str);
// 	char test1str1[]= "second-node!!!";
// 	ft_lstadd_back(&test1, ft_lstnew(test1str1));
// 	char test1str2[]= "third-node :DDD";
// 	//
// 	ft_lstadd_back(&test1, ft_lstnew(test1str2));
// 		printf("lstiter_test1: [\n");
// 			printalist(&test1, 1);
// 		printf("],\n");
// 	//
// 	t_list *result1 = ft_lstmap(test1, ftest_toupper, free);
// 		printf("lstiter_test1-after: [\n");
// 			printalist(&test1, 1);
// 		printf("],\n");
// 	//
// 	ft_lstclear(&test1, free);
// 	ft_lstclear(&result1, free);
// 	return 0;
// }
