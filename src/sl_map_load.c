/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:53:12 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 03:15:12 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>  //malloc(), free();
#include <stdbool.h> //'bool', true, false;
#include <stdio.h> //puts(), perror();
#include <fcntl.h> 	//open()
#include <unistd.h>	//read()

static bool sl_validate_map_ring(t_slmap *map, char c)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->lines[0][x] != c || map->lines[map->height - 1][x] != c)
			return (false);
		x++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		if (map->lines[y][0] != c || map->lines[y][map->width - 1] != c)
			return (false);
		y++;
	}
	return (true);
}

static bool sl_validate_map_char(char c, int *palette, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len / 2)
	{
		if (palette[i * 2] == c)
			palette[i * 2 + 1]--;
		if (palette[i * 2 + 1] < 0)
			return (false);
		i++;
	}
	return (true);
}

static bool sl_validate_map(t_slmap *map)
{
	int	x;
	int	y;

	map->width = ft_strlen(map->lines[0]);
	map->palettelen = sizeof(map->palette);
	if (map->width < 3)
		return (false);
	y = 0;
	while (map->lines[y] != NULL)
	{
		x = -1;
		while (map->lines[y][++x] != '\0')
			if (!sl_validate_map_char(map->lines[y][x], \
						map->palette, map->palettelen))
				return (false);
		if (x != map->width)
			return (false);
		y++;
	}
	if (y < 3 || !sl_validate_map_ring(map, *map->palette)
		|| !sl_flood_check(map->lines, map->palette[SL_START]))
		return (false);
	map->height = y;
	return (true);
}

// extra function because 25 line rule :_)
static int	sl_load_maps2(char *buffer, t_slmap *maps, int i)
{
	int read_return;

	read_return = read(maps[i].fd, buffer, SL_MAX_MAP_BYTES - 1);
	if (read_return < 0)
		return (sl_free_maps(maps, i), \
				sl_error("file read failed, " \
				"optional: change SL_READMODE in so_long.h"));
	if (read(maps[i].fd, buffer + read_return, 1) != 0)
		return (sl_free_maps(maps, i), \
				sl_error("SL_MAX_MAP_BYTES, change in so_long.h"));
	buffer[read_return] = '\0';
	maps[i].lines = ft_split(buffer, '\n');
	if (!maps[i].lines)
		return (sl_free_maps(maps, i), \
				sl_error("ft_split failed"));
	if (!sl_validate_map(&maps[i]))
		return (sl_free_maps(maps, i), \
				sl_error("\nERROR: mapfailure: width/height/palette\n"));
	return (0);
}

// SL_MAX_MAP_BYTES  defaults to:  16384 which is (16 * 1024);
// SL_READMODE       defaults to:  O_RDWR;
// returns 0 on success.
int	sl_load_maps(int argc, char **argv, char *buffer, t_slmap *maps)
{
	size_t	strlen;
	int		i;
	int		r;

	i = -1;
	while (++i < argc)
	{
		strlen = ft_strlen(argv[i]);
		if (strlen < 5 || ft_strncmp(argv[i] + strlen - 4, ".ber", 4))
			return (sl_free_maps(maps, i), \
					sl_error("file has no \".ber\" extension."));
		maps[i].fd = open(argv[i], SL_READMODE);
		if (!maps[i].fd)
			return (sl_free_maps(maps, i), \
					sl_error("invalid path/file permissions"));
		r = sl_load_maps2(buffer, maps, i);
		if (r)
			return (r);
	}
	return (0);
}
