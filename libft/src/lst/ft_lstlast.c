/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:22:37 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:35:57 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

// void printalist(t_list **start_node, int tabs)
// {
// 	t_list	*ptr;
// 	int 	t;
// 	int		i = 0;
// 	//
// 	if (!start_node || tabs < 0)
// 		return ;
// 	ptr = *start_node;
// 	while (ptr)
// 	{
// 		t = -1;
// 		while (++t < tabs)
// 			printf("\t");
// 		printf("node%d->content\t= \"%s\",\n", i, (char *)ptr->content);
// 		t = -1;
// 		while (++t < tabs)
// 			printf("\t");
// 		printf("node%d->next\t= %p", i, &ptr->next);
// 		if (ptr->next)
// 			printf(",");
// 		printf("\n\n");
// 		ptr = ptr->next;
// 		i++;
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	t_list *test0 = ft_lstnew("startnode");
// 	ft_lstadd_back(&test0, ft_lstnew("0123456789"));
// 	ft_lstadd_back(&test0, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test0, ft_lstnew("abcdefg"));
// 	ft_lstadd_back(&test0, ft_lstnew("===+==="));
// 	printf("lstlast_test0: [\n");
// 		printalist(&test0, 1);
// 	printf("],\n");
// 	t_list *test0result = ft_lstlast(test0);
// 	printalist(&test0result, 0);
// 	//
// 	t_list *test1 = ft_lstnew("");
// 	printf("lstlast_test1: [\n");
// 		printalist(&test1, 1);
// 	printf("],\n");
// 	t_list *test1result = ft_lstlast(test1);
// 	printalist(&test1result, 0);
// 	//
// 	t_list *test2 = ft_lstnew(NULL);
// 	printf("lstlast_test2: [\n");
// 		printalist(&test2, 1);
// 	printf("],\n");
// 	t_list *test2result = ft_lstlast(test2);
// 	printalist(&test2result, 0);
// 	return 0;
// }
