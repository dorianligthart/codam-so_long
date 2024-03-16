/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_set_palette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:18:11 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 03:18:54 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
#include <limits.h>

//in case of adding something, update the enum in ./so_long.h accordingly
//tip: keep INT_MAX characters high up since it'll be checked most;
//
//my def:
//1=wall, 0=ground, C=collectable, E=exit(once), P=start_pos(once);
int	*sl_setpalette(int *palette)
{
	palette[0] = '1';
	palette[1] = INT_MAX;
	palette[2] = '0';
	palette[3] = INT_MAX;
	palette[4] = 'C';
	palette[5] = INT_MAX;
	palette[6] = 'E';
	palette[7] = 1;
	palette[8] = 'P';
	palette[9] = 1;
	return (palette);
}