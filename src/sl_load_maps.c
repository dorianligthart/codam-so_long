/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:53:12 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 07:58:44 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>
#include <stdlib.h>  //malloc(), free();
#include <stdio.h> //puts(), perror();
#include <fcntl.h> 	//open()
#include <unistd.h>	//read()
#include "so_long.h"

//TODO: implement (flood-fill | breadth-first-search) algorithm.
//TODO: (flood-fill | breadth-first-search): add char * support instead of char.
//
//c1 must only appear once in map
//returns 0 on success;
//returns 1 on fail;
static bool	sl_mapcc_touch(char **map, char c1, char c2, char *delim)
{
	(void)map;
	(void)c1;
	(void)c2;
	(void)delim;
	// char	*check;
	// t_slvec4 v4;

	// v4.b = ft_len(map[0], sizeof(char));
	// v4.a = ft_len(map, sizeof(char *));
	// check = (char *)malloc((v4.a * v4.b) * sizeof(char));
	// ft_bzero(check, (v4.a * v4.b) * sizeof(char));
	// ft_mapchr(map, c1, &v4.x, &v4.y);
	// while (map[v4.a][v4.b + v4.x])
	// {
	// 	while (++v4.b < )
					
	// }	
	// ft_mapchr(map, c2, &v4.x, &v4.y);
	// if ()
	// 	return (free(check), sl_berror("map failed BFS/floodfill."));
	return (true);
}

static bool sl_mapc_isborder(t_slmap *map, char *characters)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map->width)
	{
		if (!ft_strchr(characters, map->lines[map->height - 1][x])
			|| !ft_strchr(characters, map->lines[0][x]))
			return (sl_berror("map border (x axis) character invalid"));
		x++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		if (!ft_strchr(characters, map->lines[y][map->width - 1])
			|| !ft_strchr(characters, map->lines[y][0]))
			return (sl_berror("map border (y axis) character invalid"));
		y++;
	}
	return (true);
}

static bool sl_map_isvalid(t_slmap *map, int *palette)
{
	size_t	x;
	size_t	x_check;
	size_t	y;

	y = 0;
	while (map->lines[y] != NULL)
	{
		x = 0;
		while (map->lines[y][x] != '\0')
		{
			if (palette[map->lines[y][x] * 2 + 1]-- == 0)
				return (sl_berror("map content character limit exceeded."));
			x++;
		}
		if (y > 0 && x != x_check)
			return (sl_berror("map lines are not the same length."));
		x_check = x;
		y++;
	}
	map->height = y;
	map->width = x;
	if (map->width < 3 || map->height < 3)
		return (sl_berror("map width or height is smaller than 3."));
	return (true);
}

// SL_MAX_MAP_BYTES  defaults to:  16384 which is (16 * 1024);
// SL_READMODE       defaults to:  O_RDWR;
// returns 0 on success.
static bool	sl_load_a_map(t_slmap *map, char *buffer)
{
	size_t	strlen;
	int		read_return;

	map->lines = NULL;
	strlen = ft_strlen(map->path);
	if (strlen < 5 || ft_strncmp(map->path + strlen - 4, ".ber", 4))
		return (sl_berror("file has no \".ber\" extension."));
	map->fd = open(map->path, SL_READMODE);
	if (map->fd < 0)
		return (sl_berror("invalid path/file permissions."));
	read_return = read(map->fd, buffer, SL_MAP_BUFFER - 1);
	if (read_return < 0)
		return (sl_berror("file read failed"));
	if (read(map->fd, buffer + read_return, 1) != 0)
		return (sl_berror("SL_MAP_BUFFER too small, change it in so_long.h."));
	buffer[read_return] = '\0';
	map->lines = ft_split(buffer, '\n');
	if (!map->lines)
		return (sl_berror("ft_split() malloc has failed."));
	for (int x = 0; map->lines[x]; x++)
		printf("%s\n", map->lines[x]);
	return (true);
}

bool	sl_load_maps(t_solong *sl, int argc, char **argv, char *buffer)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		sl->maps[i].path = argv[i];
		if (!sl_load_a_map(&sl->maps[i], buffer)
			|| !sl_map_isvalid(&sl->maps[i], sl->palette)
			|| !sl_mapc_isborder(&sl->maps[i], "1")
			|| !sl_mapcc_touch(sl->maps[i].lines, \
				SL_START / 2, SL_EXIT / 2, "1")
			|| !sl_mapcc_touch(sl->maps[i].lines, \
				SL_START / 2, SL_COLLECT / 2, "1"))
		{
			sl_free_maps(sl->maps, i + (sl->maps[i].lines != NULL));
			return (false);
		}
	}
	return (true);
}
