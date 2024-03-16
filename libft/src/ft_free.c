/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:15:10 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 01:59:53 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

//frees an array of pointers.
void	ft_free(void **ptr)
{
	while (*ptr)
	{
		free(*ptr);
		(*ptr) += sizeof(void *);
	}
	free(ptr);
	ptr = NULL;
}