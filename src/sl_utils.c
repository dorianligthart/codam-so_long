/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:45:34 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 08:27:52 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <MLX42/MLX42.h> //Too many to list;
#include <stdbool.h>
#include <stdio.h> //puts(), perror();
#include <stdlib.h>
#include <fcntl.h> //open()
#include <unistd.h> //read()

//in case of adding something, update the enum sl_palette in so_long.h;
//default / subject pdf definition:
//	1=wall_char, 		0=ground_char, 		C=collectable_char,
//	E=exit_char(once),	P=start_char(once);
//make sure to name the xpm files the single character_it_indicates + ".xpm";
//	e.g wall_char=1, xpmfile located in './assets/xpm/1.xpm';
//		appearance_limit = palett['1' * 2 + 1];
int	*sl_load_palette(int *palette)
{
	char	buf[SL_PALETTE_HEADERLEN];
	int		fd;
	int		read_return;

	ft_bzero(palette, SL_COUNT * sizeof(int));
	fd = open(SL_PALETTE_PATH, O_RDONLY);
	read_return = read(fd, buf, SL_PALETTE_HEADERLEN);
	if (read_return != SL_PALETTE_HEADERLEN)
		return ((void *)sl_berror(SL_PALETTE_PATH": header invalid."));
	while (read_return)
	{
		read_return = read(fd, buf, SL_PALETTE_LINELEN);
		if (read_return < 0)
			return ((void *)sl_berror("SYSCALL read failure."));
		if (read_return != SL_PALETTE_LINELEN && read_return != 0)
			return ((void *)sl_berror(SL_PALETTE_PATH": line-width invalid."));
		buf[SL_PALETTE_LINELEN] = '\0';
		palette[buf[0] * 2] = buf[0];
		palette[buf[0] * 2 + 1] = ft_atoi(buf + 2);
	}
	close(fd);
	return (palette);
}

bool	sl_load_xpms(xpm_t **xpm, int *palette)
{
	int		i;
	char	*result;
	size_t	strlen;

	strlen = ft_strlen(SL_XPM_PATH);
	result = malloc((strlen + 6) * sizeof(char));
	result[strlen + 5] = '\0';
	ft_memcpy(result, SL_XPM_PATH, strlen);
	ft_memcpy(result + strlen + 1, ".xpm", 4);
	i = 0;
	while (i < SL_COUNT / 2)
	{
		if (palette[i * 2])
		{
			result[strlen] = palette[i * 2];
			printf("XPM IMPORT %d: '%s'\n", i * 2, result);
			xpm[i] = mlx_load_xpm42((const char *)result);
			if (!xpm[i])
				return (free(result), sl_berror("failed loading .xpm file."));
		}
		i++;
	}
	free(result);
	return (true);
}

void	sl_free_maps(t_slmap *maps, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_free((void **)maps[i].lines);
		free(maps[i].lines);
		i++;
	}
}

int	sl_error(const char *msg)
{
	printf(RED"%s\n"RESET, msg);
	return (EXIT_FAILURE);
}

bool	sl_berror(const char *msg)
{
	printf(RED"%s\n"RESET, msg);
	return (false);
}
