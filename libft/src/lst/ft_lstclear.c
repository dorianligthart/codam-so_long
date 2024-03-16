/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:05 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:35:47 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = tmp;
	}
	*lst = NULL;
	lst = NULL;
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
// 		printf(""
//"node%d->content=\"%s\",\t%p", i, (char *)ptr->content, &ptr->next);
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
// 	ft_lstadd_back(&test0, ft_lstnew("0123456789"));
// 	ft_lstadd_back(&test0, ft_lstnew("ABCDEFG"));
// 	ft_lstadd_back(&test0, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test0, ft_lstnew("===+==="));
// 	printf("lstclear_test0: [\n");
// 		printalist(&test0, 1);
// 	printf("],\n");
// 	ft_lstclear(&test0, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test0, 1);
// 	printf("],\n");
//	//
// 	t_list *test1 = ft_lstnew("startnode");
// 	ft_lstadd_back(&test1, ft_lstnew(NULL));
// 	ft_lstadd_back(&test1, ft_lstnew("ABCDEFG"));
// 	ft_lstadd_back(&test1, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test1, ft_lstnew("===+==="));
// 	printf("lstclear_test1: [\n");
// 		printalist(&test1, 1);
// 	printf("],\n");
// 	ft_lstclear(&test1, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test1, 1);
// 	printf("],\n");
//	//	
// 	t_list *test2 = ft_lstnew("startnode");
// 	ft_lstadd_back(&test2, ft_lstnew("0123456789"));
// 	ft_lstadd_back(&test2, ft_lstnew("ABCDEFG"));
// 	ft_lstadd_back(&test2, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test2, ft_lstnew(NULL));
// 	printf("lstclear_test2: [\n");
// 		printalist(&test2, 1);
// 	printf("],\n");
// 	ft_lstclear(&test2, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test2, 1);
// 	printf("],\n");
//	//
// 	t_list *test3 = ft_lstnew("startnode");
// 	ft_lstadd_back(&test3, ft_lstnew(""));
// 	ft_lstadd_back(&test3, ft_lstnew("ABCDEFG"));
// 	ft_lstadd_back(&test3, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test3, ft_lstnew("===+==="));
// 	printf("lstclear_test3: [\n");
// 		printalist(&test3, 1);
// 	printf("],\n");
// 	ft_lstclear(&test3, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test3, 1);
// 	printf("],\n");
//	//
// 	t_list *test4 = ft_lstnew("startnode");
// 	ft_lstadd_back(&test4, ft_lstnew("0123456789"));
// 	ft_lstadd_back(&test4, ft_lstnew("ABCDEFG"));
// 	ft_lstadd_back(&test4, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test4, ft_lstnew(""));
// 	printf("lstclear_test4: [\n");
// 		printalist(&test4, 1);
// 	printf("],\n");
// 	ft_lstclear(&test4, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test4, 1);
// 	printf("],\n");
//	//
// 	t_list *test5 = ft_lstnew(NULL);
// 	printf("lstclear_test5: [\n");
// 		printalist(&test5, 1);
// 	printf("],\n");
// 	ft_lstclear(&test5, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test5, 1);
// 	printf("],\n");
//	//
// 	t_list *test6 = ft_lstnew("");
// 	printf("lstclear_test6: [\n");
// 		printalist(&test6, 1);
// 	printf("]\n");
// 	ft_lstclear(&test6, free);
// 	printf("lstclear_test0-after: [\n");
// 	printalist(&test6, 1);
// 	printf("]\n");
//	//
// 	return 0;
// }
