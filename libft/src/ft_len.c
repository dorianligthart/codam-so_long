/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:53:47 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 04:57:36 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_len(void **ptr, size_t ptrsize)
{
	size_t	ret;

	ret = 0;
	while (ptr + ret)
		ret += ptrsize;
	return (ret);
}
