/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:11:36 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/17 08:20:31 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMATIONS_H__
# define __ANIMATIONS_H__

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_animation {
  t_list*   frames;
  int       frame_speed;        // The speed of the animation in miliseconds
  double    accum;              // The accumulator to controll the speed
  int       current_frame_num;  // Which frame is selected
  int       mirrored;
  long int  frame_count;        // The frame count
} t_animation;

typedef struct sprite_slice {
  int x;
  int y;
  int width;
  int height;
  int padding_x;
  int padding_y;
} sprite_slice;

typedef struct s_sprite {
  mlx_image_t*  sprite_img;
  mlx_t*        mlx;
} t_sprite;

/* SPRITES */
t_sprite      new_sprite(char* file_name, mlx_t* mlx);
t_animation*  slice_sprite(t_sprite* s, sprite_slice slice, int mirrored, int frames, int delay);
void          destroy_sprite(t_sprite* s);

#define BPP sizeof(int32_t)

static int get_rgba(int r, int g, int b, int a) {
  return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * In MLX42 Colors are as follows:
 * 0000 0000 A (1st byte) -> uint8_t because it's 8 bits
 * 0000 0000 R (2nd byte)
 * 0000 0000 G (3rd byte)
 * 0000 0000 B (4th byte)
 **/
int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y) {
  if (x > image->width || y > image->height)
    return 0xFF000000;
  uint8_t* pixelstart = image->pixels + (y * image->width + x) * BPP;
  return get_rgba(*(pixelstart), *(pixelstart + 1),
    * (pixelstart + 2), *(pixelstart + 3));
}

void error(void);

t_sprite new_sprite(char* file_path, mlx_t* mlx)
{
  mlx_image_t* img;
  mlx_texture_t* texture;

  // Load png
  texture = mlx_load_png(file_path);
  if (!texture)
    error();

  // Create image from png texture
  img = mlx_texture_to_image(mlx, texture);
  if (!img)
    error();

  mlx_delete_texture(texture);

  return (t_sprite){img, mlx};
}

void    destroy_sprite(t_sprite* s)
{
    if (!s)
        error();
    mlx_delete_image(s->mlx, s->sprite_img);
}

static void add_frame(t_animation* a, t_sprite* s, \
                      sprite_slice slice, int mirrored)
{
    mlx_image_t* frame;

    frame = mlx_new_image(s->mlx, slice.width - (slice.padding_x * 2), slice.height - (slice.padding_y * 2));
    if (!frame)
        error();
    for (int i = 0; i < slice.height - (slice.padding_y * 2); i++) {
        for (int j = 0; j < slice.width - (slice.padding_x * 2); j++) {
            if (mirrored)
                mlx_put_pixel(frame, (slice.height - (slice.padding_y * 2)) - j - 1, i, mlx_get_pixel(s->sprite_img, slice.x + j + slice.padding_x, slice.y + i + slice.padding_y));
            else
                mlx_put_pixel(frame, j, i, mlx_get_pixel(s->sprite_img, slice.x + j + slice.padding_x, slice.y + i + slice.padding_y));
        }
    }
    ft_lstadd_back(&a->frames, ft_lstnew(frame));
}

t_animation* slice_sprite(t_sprite* s, sprite_slice slice, \
                          int mirrored, int frames, int delay)
{
    t_animation *   a;

    a = (t_animation*)calloc(sizeof(t_animation), 1);
    if (!a)
        error();
    *a = (t_animation){NULL, delay, 0, 0, mirrored, 0, 0};
    for (int i = 0; i < frames; i++) {
        add_frame(a, s, slice, mirrored);
        slice.x += slice.width;
        if ((uint32_t)slice.x >= s->sprite_img->width) {
            slice.x = 0;
            slice.y += slice.height;
        }
    }
    return (a);
}

#endif