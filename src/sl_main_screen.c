/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:14:39 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 04:32:02 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h> //Too many to list;
#include "so_long.h"
#include <stdint.h>  //'int32_t';
#include <limits.h>  //INT_MAX;
#include <stdio.h>	 //perror();
#include <stdlib.h>	 //perror();

// mlx_loop_hook(sl->mlx, ft_randomize, sl->image);
//read and parse and mlx loop
//
	// return (0);
	// if (sl->width < 800 || sl->height < 600)
	// 	return (perror("ERROR: get bigger monitor\n"), EXIT_FAIL);
/*
int	main2(t_solong *sl)
{
	mlx_get_monitor_size(0, &(sl->width), &(sl->height));
	printf("%d, %d\n", sl->width, sl->height);
	sl->width = SL_STARTING_WIDTH;
	sl->height = SL_STARTING_HEIGHT;
	sl->mlx = mlx_init(sl->width, sl->height, "Adventure time :)", false);
	if (!sl->mlx)
		return (ft_free((void **)sl->lines, sizeof(char *)), \
				sl_error(mlx_strerror(mlx_errno)));
	sl->bg_img = mlx_new_image(sl->mlx, sl->width, sl->height);
	if (!sl->bg_img)
		return (mlx_close_window(sl->mlx), \
				ft_free((void **)sl->lines, sizeof(char *)), \
				sl_error(mlx_strerror(mlx_errno)));
	if (!sl_load_textures(SL_TEXTURE_PATH, ft_strlen(SL_TEXTURE_PATH), sl))
		return (mlx_close_window(sl->mlx), \
				ft_free((void **)sl->lines, sizeof(char *)), \
				sl_error(mlx_strerror(mlx_errno)));
	if (!sl_render(sl))
		return (mlx_close_window(sl->mlx), \
				ft_free((void **)sl->lines, sizeof(char *)), \
				sl_error(mlx_strerror(mlx_errno)));
	return (0);
}
*/

//TODO: paint bg, paint walls, paint player, paint exit;
//
//TODO: add saving world to tmp build folder;
	//on a finished level, save P & E next to eachother.
//
//TODO: decide if the game is keyboard only or with mouse.
//
//TODO: implement main screen, 3 buttons: play, options, quit;
	//initially start in 800x600
	//options-> ( fullscreen_bool | widthXheight );
	//play-> order of argv, and add endscreen if player passed final level.
//
///////////////////////////
//less important todo's: //
//TODO: implement 4 different biomes, ice, desert, plain, jungle.
	//amount_of_levels_per_biome = argc / 4.
	//load 508 textures into xpm_t *array. (127 per biome)
//TODO: Set palette per map?
//TODO: Generate maps based on xpm file's alpha/red/green/blue channels :)
int	main(int argc, char *argv[])
{
	t_solong	sl;
	char		buffer[SL_MAX_MAP_BYTES];
	// int			palette[15];
	xpm_t		*textures[SL_COUNT / 2];

	if (argc < 2 || !*argv[1])
		return (perror("ERROR: provide map(s)."), 1);
	argv++;
	argc--;
	sl.maps = (t_slmap *)malloc((argc + 1) * sizeof(t_slmap));
	if (!sl.maps)
		return (perror("ERROR: malloc failure."), 1);
	(&sl.maps)[argc] = NULL;
	if (sl_load_maps(argc, argv, buffer, sl.maps))
		return (free(sl.maps), 1);
	// sl.mapspalette = sl_setpalette(palette);
	sl.textures = textures;
	return (0);
}
