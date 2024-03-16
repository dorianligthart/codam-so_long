/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:28:06 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 04:37:02 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "so_long.h"

bool	sl_flood_check(t_slmap *map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
		while (x < map->width)
			if (map->lines[y][x] == c)
				break ;
	printf("Breaked on index [%d][%d]\n", y, x);
	return (true);
}
