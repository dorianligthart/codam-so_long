/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:10:38 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 03:37:04 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	sl_render(t_solong *sl, )
{
	if (mlx_image_to_window(sl->mlx, sl->bg_img, 0, 0) == -1)
		return (false);
	mlx_key_hook(sl->mlx, sl_player_hook, (void *)sl);
	mlx_loop(sl->mlx);
	mlx_terminate(sl->mlx);
	ft_free((void **)sl->lines, sizeof(char *));
	return (true);
}