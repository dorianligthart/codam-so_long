/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:34:38 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 08:25:16 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include "libft.h"

//1024 * 16
# ifndef SL_MAP_BUFFER
#  define SL_MAP_BUFFER 16384
# endif

# ifndef SL_STARTING_WIDTH
#  define SL_STARTING_WIDTH 800
# endif

# ifndef SL_STARTING_HEIGHT
#  define SL_STARTING_HEIGHT 600
# endif

//./xpm:
# ifndef SL_XPM_PATH
#  define SL_XPM_PATH "./assets/xpm/"
# endif
//'palette.conf' (the file to configure limits of characters for maps):
# ifndef SL_PALETTE_PATH
#  define SL_PALETTE_PATH "./assets/palette.conf"
# endif
# ifndef SL_PALETTE_HEADERLEN
#  define SL_PALETTE_HEADERLEN 177
# endif
# ifndef SL_PALETTE_LINELEN
#  define SL_PALETTE_LINELEN 13
# endif

// readmode for reading maps = O_RDONLY || O_RDWR 
# ifndef SL_READMODE
#  define SL_READMODE O_RDWR
# endif

//default palette enum :)
//AM = AMOUNT
typedef enum sl_palette
{
	SL_WALL = '1' * 2,
	SL_WALL_AM = SL_WALL + 1,
	SL_SPACE = '0' * 2,
	SL_SPACE_AM = SL_SPACE + 1,
	SL_COLLECT = 'C' * 2,
	SL_COLLECT_AM = SL_COLLECT + 1,
	SL_EXIT = 'E' * 2,
	SL_EXIT_AM = SL_EXIT + 1,
	SL_START = 'S' * 2,
	SL_START_AM = SL_START + 1,
	SL_COUNT = 256,
} t_palette;

//for BFS/floodfill
typedef struct s_slvec4
{
	size_t	a;
	size_t	b;
	size_t	x;
	size_t	y;
} t_slvec4;

typedef struct s_slmap
{
	mlx_image_t	*bg_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*collect_img;
	char		*path;
	int			fd;
	char		**lines;
	size_t		width;
	size_t		height;
} t_slmap;

typedef struct s_solong
{
	mlx_image_t	*enemy_img;
	mlx_image_t	*player_img;
	xpm_t		*xpms;
	int			*palette;
	t_slmap		*maps;
	mlx_t		*mlx;
	int			multiplier; //mlx_stretch_image
	size_t		width;
	size_t		height;
} t_solong;

//	mlx_set_setting(MLX_STRETCH_IMAGE, true); //set window properties :D

//so_long utils:

//returns false
bool	sl_berror(const char *msg);
//returns EXIT_FAILURE
int		sl_error(const char *msg);
//returns int array of size 128;
int		*sl_load_palette(int *palette);
bool 	sl_load_maps(t_solong *sl, int argc, char **argv, char *buffer);
bool	sl_load_xpms(xpm_t **xpm, int *palette);

void	sl_free_maps(t_slmap *maps, size_t n);

//	map_load && map_validate entry functions.

//TODO: render these parsed scheise into a window scene: 
// int		sl_render(t_solong *sl, t_slmap *map);
// void	sl_player_hook(mlx_key_data_t keydata, void *param);

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
