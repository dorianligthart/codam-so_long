/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:43:21 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 08:26:15 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h> //Too many to list;
#include "so_long.h"
#include <stdint.h>  //'int32_t';
#include <limits.h>  //INT_MAX;
#include <stdio.h>	 //perror();
#include <stdlib.h>	 //perror();

void	sl_player_hook(mlx_key_data_t keydata, void *param)
{
	t_solong	*sl;

	sl = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(sl->mlx);
	if (keydata.key == MLX_KEY_W)
		sl->player_img->instances[0].y -= 96;
	if (keydata.key == MLX_KEY_S)
		sl->player_img->instances[0].y += 96;
	if (keydata.key == MLX_KEY_A)
		sl->player_img->instances[0].x -= 96;
	if (keydata.key == MLX_KEY_D)
		sl->player_img->instances[0].x += 96;
}

int	sl_render_a_map(t_solong *sl, t_slmap *map)
{
	xpm_t *xpm;

	xpm = &(sl->xpms[SL_SPACE]);
	xpm->cpp = 2;
	map->bg_img = mlx_texture_to_image(sl->mlx, &xpm->texture);
	if (!map->bg_img)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(sl->mlx, map->bg_img, 0, 0) == -1)
		return (EXIT_FAILURE);
	mlx_loop(sl->mlx);
	return (EXIT_SUCCESS);
}

// mlx_loop_hook(sl->mlx, ft_randomize, sl->image);
	// mlx_get_monitor_size(0, &(sl->width), &(sl->height));
	// printf("%d, %d\n", sl->width, sl->height);
	// if (sl->width < 800 || sl->height < 600)
	// 	return (perror("ERROR: get bigger monitor\n"), EXIT_FAIL);
	// return (free(sl->maps), sl_error(mlx_strerror(mlx_errno)));
//main2, all about mlx stuff, rendering different scenes.
static int	main2(t_solong *sl, int mapcount)
{
	// int	i;

	(void)sl;
	(void)mapcount;
	// sl->mlx = mlx_init(SL_STARTING_WIDTH, SL_STARTING_HEIGHT, "so_long", false);
	// if (!sl->mlx)
		
	// i = -1;
	// while (++i < mapcount)
	// {
	// 	if (sl_render_a_map(sl, &sl->maps[i]))
	// 		break ;
	// 	// mlx_key_hook(sl->mlx, sl_player_hook, (void *)sl);
	// 	// mlx_loop(sl->mlx);
	// }
	// mlx_close_window(sl->mlx);
	// mlx_terminate(sl->mlx);
	sl_free_maps(sl->maps, mapcount);
	free(sl->maps);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_solong	sl;
	char		buffer[SL_MAP_BUFFER];
	int			palette[SL_COUNT];
	xpm_t		*xpms[SL_COUNT / 2];

	if (argc < 2)
		return (perror("provide map(s)."), 1);
	argv++;
	argc--;
	sl.maps = (t_slmap *)malloc((argc + 1) * sizeof(t_slmap));
	if (!sl.maps)
		return (sl_error("malloc failure in main()"));
	sl.palette = sl_load_palette(palette);
	if (!sl.palette)
		return (free(sl.maps), EXIT_FAILURE);
	for (int i = 0; i < 256; ++i) printf("%3i: %1c  ", i, palette[i]);
	ft_memset(sl.maps + argc, 0, sizeof(t_slmap));
	sl.xpms = ft_memset(xpms, '\0', SL_COUNT / 2 * sizeof(xpm_t *));
	if (!sl_load_maps(&sl, argc, argv, buffer))
		return (free(sl.maps), sl_error("failed to load maps"));
	if (!sl_load_xpms(&sl.xpms, sl.palette))
		return (sl_free_maps(sl.maps, argc), free(sl.maps), EXIT_FAILURE);
	return (main2(&sl, argc));
}
//TODO: decide on enemies :)
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

