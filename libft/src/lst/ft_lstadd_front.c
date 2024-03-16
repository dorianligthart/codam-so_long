/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:10:34 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:34:15 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// void printalist(t_list **start_node, int tabs)
// {
// 	t_list	*ptr;
// 	int 	t;

// 	if (!start_node)
// 		return ;
// 	ptr = *start_node;
// 	while (ptr)
// 	{
// 		t = -1;
// 		while (++t < tabs)
// 			write(1, "\t", 1);
// 		printf("%s\n", (char *)ptr->content);
// 		ptr = ptr->next;
// 	}
// }

// void nodeprint(char *nodename, char *str)
// {
// 	printf("\t\t%s:\"%s\"\n", nodename, str);
// }

// void test0(char *title)
// {
// 	printf("%s: [\n", title);
// 	t_list	*node1 = ft_lstnew("0123456789");
// 	t_list	*node2 = ft_lstnew("abcdefg");
// 	t_list	*node3 = ft_lstnew("ABCDEFGH");	
// 	if (!node1 || !node2 || !node3)
// 		return ;
// 	printf("\tNODES: [\n");
// 		nodeprint("node1", node1->content);
// 		nodeprint("node2", node2->content);
// 		nodeprint("node3", node3->content);
// 	printf("\t]\n");
// 	ft_lstadd_front(&node1, node2);
// 	ft_lstadd_front(&node1, node3);
// 	printf("\tRESULT: [\n");
// 		printalist(&node1, 2);	
// 	printf("\t]\n");
// 	free(node1);	
// 	free(node2);	
// 	free(node3);
// 	printf("]\n");	
// }

// void test1(char *title)
// {
// 	printf("%s: [\n", title);
// 	t_list	*node1 = ft_lstnew("");
// 	t_list	*node2 = ft_lstnew("abcdefg");
// 	t_list	*node3 = ft_lstnew("ABCDEFGH");	
// 	if (!node1 || !node2 || !node3)
// 		return ;
// 	printf("\tNODES: [\n");
// 		nodeprint("node1", node1->content);
// 		nodeprint("node2", node2->content);
// 		nodeprint("node3", node3->content);
// 	printf("\t]\n");
// 	ft_lstadd_front(&node1, node2);
// 	ft_lstadd_front(&node1, node3);
// 	printf("\tRESULT: [\n");
// 		nodeprint("node1", node1->content);
// 		nodeprint("node2", node1->next->content);
// 		nodeprint("node3", node1->next->next->content);
// 	printf("\t]\n");
// 	free(node1);	
// 	free(node2);	
// 	free(node3);	
// 	printf("]\n");	
// }

// void test2(char *title)
// {
// 	printf("%s: [\n", title);
// 	t_list	*node1 = ft_lstnew(NULL);
// 	t_list	*node2 = ft_lstnew("abcdefg");
// 	t_list	*node3 = ft_lstnew("ABCDEFGH");	
// 	if (!node1 || !node2 || !node3)
// 		return ;
// 	printf("\tNODES: [\n");
// 		nodeprint("node1", node1->content);
// 		nodeprint("node2", node2->content);
// 		nodeprint("node3", node3->content);
// 	printf("\t]\n");
// 	ft_lstadd_front(&node1, node2);
// 	ft_lstadd_front(&node1, node3);
// 	printf("\tRESULT: [\n");
// 		nodeprint("node1", node1->content);
// 		nodeprint("node2", node1->next->content);
// 		nodeprint("node3", node1->next->next->content);
// 	printf("\t]\n");
// 	free(node1);	
// 	free(node2);	
// 	free(node3);	
// 	printf("]\n");	
// }

// int main(void)
// {
// 	test0("add_front TEST 0");
// 	test1("add_front TEST 1");
// 	test2("add_front TEST 2");
// 	return 0;
// }
