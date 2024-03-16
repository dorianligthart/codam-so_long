/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:34:38 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 04:37:07 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include "libft.h"

//1024 * 16
# ifndef SL_MAX_MAP_BYTES
#  define SL_MAX_MAP_BYTES 16384
# endif

# ifndef SL_STARTING_WIDTH
#  define SL_STARTING_WIDTH 800
# endif

# ifndef SL_STARTING_HEIGHT
#  define SL_STARTING_HEIGHT 600
# endif

# ifndef SL_TEXTURE_PATH
#  define SL_TEXTURE_PATH "../textures/0/"
# endif

// O_RDONLY || O_RDWR 
# ifndef SL_READMODE
#  define SL_READMODE O_RDWR
# endif

//default palette enum :)
//AM = AMOUNT
typedef enum sl_palette
{
	SL_WALL,
	SL_WALL_AM,
	SL_SPACE,
	SL_SPACE_AM,
	SL_COLLECT,
	SL_COLLECT_AM,
	SL_EXIT,
	SL_EXIT_AM,
	SL_START,
	SL_START_AM,
	SL_COUNT,
} t_palette;

//TODO: decide on enemies :)
	// mlx_image_t	*enemy_img;
typedef struct s_slmap
{
	mlx_image_t	*bg_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*collect_img;
	int			*palette;
	int			palettelen;
	char		*path;
	int			pathlen;
	int			fd;
	char		**lines;
	int			width;
	int			height;
} t_slmap;


typedef struct s_solong
{
	xpm_t		**textures;
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	t_slmap		*maps;
	// int			multiplier; //mlx_stretch_image
	int			width;
	int			height;
} t_solong;

//	mlx_set_setting(MLX_STRETCH_IMAGE, true); //set window properties :D

//so_long utils//
//from top to bottom:
//	utils:
int		sl_error(const char *msg);
void	sl_free_maps(t_slmap *maps, int n);
int		*sl_setpalette(int *palette);
bool	sl_load_textures(char *str, size_t strlen, t_solong *sl, t_slmap *map);

//	map_load && map_validate entry functions.
int		sl_load_maps(int argc, char **argv, char *buffer, t_slmap *maps);
bool	sl_flood_check(t_slmap *map, char c);

//TODO: render these parsed scheise into window: 
int		sl_render(t_solong *sl, t_slmap *map);
void	sl_player_hook(mlx_key_data_t keydata, void *param);

//boring terminal color defines:
# ifndef RESET
#  define RESET "\033[0m"
# endif //RESET
# ifndef RED
#  define RED "\033[0;31m"
# endif //RED
# ifndef GREEN
#  define GREEN "\033[0;32m"
# endif //GREEN
# ifndef YELLOW
#  define YELLOW "\033[0;33m"
# endif //YELLOW
# ifndef BLUE
#  define BLUE "\033[0;34m"
# endif //BLUE
# ifndef MAGENTA
#  define MAGENTA "\033[0;35m"
# endif //MAGENTA
# ifndef CYAN
#  define CYAN "\033[0;36m"
# endif //CYAN
# ifndef WHITE
#  define WHITE "\033[0;37m"
# endif //WHITE
#endif