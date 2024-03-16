/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:08:19 by doligtha          #+#    #+#             */
/*   Updated: 2023/11/07 19:21:37 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*lst_it;

	size = 0;
	lst_it = lst;
	while (lst_it && ++size)
		lst_it = lst_it->next;
	return (size);
}

// // i only use 42lib functions once thorough testing has been 
// // finished for them. dont worry.
// int main(int argc, char const *argv[])
// {
// 	t_list *test0 = NULL;
// 	int res0 = ft_lstsize(test0);
// 	printf("0:%d\n", res0);
// 	ft_lstclear(&test0, free);

// 	t_list *test1 = ft_lstnew(NULL);
// 	int res1 = ft_lstsize(test1);
// 	printf("1:%d\n", res1);
// 	ft_lstclear(&test1, free);

// 	t_list *test2 = ft_lstnew("");
// 	int res2 = ft_lstsize(test2);
// 	printf("2:%d\n", res2);
// 	ft_lstclear(&test2, free);

// 	t_list *test3 = ft_lstnew("1st node :D");
// 	ft_lstadd_back(&test3, ft_lstnew("2nd node"));
// 	int res3 = ft_lstsize(test3);
// 	printf("3:%d\n", res3);
// 	ft_lstclear(&test3, free);

// 	t_list *test4 = ft_lstnew("1st xD");
// 	ft_lstadd_back(&test4, ft_lstnew("2nd xD"));
// 	ft_lstadd_back(&test4, ft_lstnew("3rd xD"));
// 	int res4 = ft_lstsize(test4);
// 	printf("4:%d\n", res4);
// 	ft_lstclear(&test4, free);

// 	t_list *test5 = ft_lstnew("1st :)");
// 	ft_lstadd_back(&test5, ft_lstnew("2nd :)"));
// 	ft_lstadd_back(&test5, ft_lstnew("3rd :)"));
// 	ft_lstadd_back(&test5, ft_lstnew("4th :D"));
// 	int res5 = ft_lstsize(test5);
// 	printf("5:%d\n", res5);
// 	ft_lstclear(&test5, free);

// 	t_list *test6 = ft_lstnew("");
// 	ft_lstadd_back(&test6, ft_lstnew("2nd :)"));
// 	ft_lstadd_back(&test6, ft_lstnew(""));
// 	ft_lstadd_back(&test6, ft_lstnew(NULL));
// 	ft_lstadd_back(&test6, ft_lstnew("final node, I think its enough test"));
// 	int res6 = ft_lstsize(test6);
// 	printf("6:%d\n", res6);
// 	ft_lstclear(&test6, free);

// 	return 0;
// }
