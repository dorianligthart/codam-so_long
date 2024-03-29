/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:15:10 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 18:59:31 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//frees an array of pointers.
void	ft_free(void **ptr)
{
	size_t n;

	n = 0;
	while (*(ptr + n))
	{
		free(*(ptr + n));
		n++;
	}
}
