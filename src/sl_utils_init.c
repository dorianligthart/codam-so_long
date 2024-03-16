/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:45:34 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 04:31:04 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <MLX42/MLX42.h> //Too many to list;
#include "so_long.h"
#include <stdio.h> //puts(), perror();
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

bool	sl_load_textures(char *str, size_t strlen, t_solong *sl, t_slmap *map)
{
	int		i;
	char	*result;

	result = malloc((strlen + 1) * sizeof(char));
	result[strlen] = '\0';
	ft_memcpy(result, str, strlen);
	ft_memcpy(result + strlen + 1, ".xpm", 4);
	i = 0;
	while (i < SL_COUNT / 2)
	{
		result[strlen - 5] = (char)map->palette[i * 2];
		(sl->textures)[i] = mlx_load_xpm42((const char *)result);
		if ((sl->textures)[i] == NULL)
			return (false);
	}
	free(result);
	return (true);
}

void	sl_free_maps(t_slmap *maps, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_free((void **)maps[i].lines);
}

int	sl_error(const char *msg)
{
	perror(RED"\n");
	perror(msg);
	perror("\n"RESET);
	return (EXIT_FAILURE);
}
