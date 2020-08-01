/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/26 20:39:40 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/03 19:08:56 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

static void	calc_sprite_three(t_data *data)
{
	data->sprite_drawinfo->drawstartx = -data->sprite_drawinfo->spritewidth /
				2 + data->sprite_drawinfo->spritescreenx;
	if (data->sprite_drawinfo->drawstartx < 0)
		data->sprite_drawinfo->drawstartx = 0;
	data->sprite_drawinfo->drawendx = data->sprite_drawinfo->spritewidth /
				2 + data->sprite_drawinfo->spritescreenx;
	if (data->sprite_drawinfo->drawendx >= data->screen_info->screenwidth)
		data->sprite_drawinfo->drawendx = data->screen_info->screenwidth - 1;
}

static void	calc_sprite_two(t_data *data)
{
	data->sprite_drawinfo->spritescreenx = (int)(
				(data->screen_info->screenwidth / 2) * (1 +
				data->sprite_drawinfo->transformx /
				data->sprite_drawinfo->transformy));
	data->sprite_drawinfo->spriteheight = ft_abs((int)(
				data->screen_info->screenheight /
				(data->sprite_drawinfo->transformy)));
	data->sprite_drawinfo->drawstarty = -data->sprite_drawinfo->spriteheight /
				2 + data->screen_info->screenheight / 2;
	if (data->sprite_drawinfo->drawstarty < 0)
		data->sprite_drawinfo->drawstarty = 0;
	data->sprite_drawinfo->drawendy = data->sprite_drawinfo->spriteheight /
				2 + data->screen_info->screenheight / 2;
	if (data->sprite_drawinfo->drawendy >= data->screen_info->screenheight)
		data->sprite_drawinfo->drawendy = data->screen_info->screenheight - 1;
	if (data->sprite_drawinfo->transformy == 0)
		data->sprite_drawinfo->transformy = 5;
	data->sprite_drawinfo->spritewidth = ft_abs((int)(
				data->screen_info->screenheight /
				(data->sprite_drawinfo->transformy)));
	calc_sprite_three(data);
}

void		calc_sprite_one(t_data *data, int i)
{
	data->sprite_drawinfo->spritex = data->sprites->x[i] - data->player->posx;
	data->sprite_drawinfo->spritey = data->sprites->y[i] - data->player->posy;
	data->sprite_drawinfo->invdet = 1.0 / (data->player->planex *
				data->player->diry - data->player->dirx * data->player->planey);
	data->sprite_drawinfo->transformx = data->sprite_drawinfo->invdet *
				(data->player->diry * data->sprite_drawinfo->spritex -
				data->player->dirx * data->sprite_drawinfo->spritey);
	data->sprite_drawinfo->transformy = data->sprite_drawinfo->invdet *
				(-data->player->planey * data->sprite_drawinfo->spritex +
				data->player->planex * data->sprite_drawinfo->spritey);
	calc_sprite_two(data);
}

static void	draw_sprite(t_data *data, int y, int texx, int texy)
{
	data->img->img_data[(data->img->x * 4 + data->img->size_line * y) + 0] =
		mlx_get_color_value(data->mlx_ptr, data->img->sprite_data[(
		texx * 4 + data->img->sp_sl * texy) + 0]);
	data->img->img_data[(data->img->x * 4 + data->img->size_line * y) + 1] =
		mlx_get_color_value(data->mlx_ptr, data->img->sprite_data[(
		texx * 4 + data->img->sp_sl * texy) + 1]);
	data->img->img_data[(data->img->x * 4 + data->img->size_line * y) + 2] =
		mlx_get_color_value(data->mlx_ptr, data->img->sprite_data[(
		texx * 4 + data->img->sp_sl * texy) + 2]);
}

void		draw_sprites_loop(t_data *data, int texx)
{
	int d;
	int texy;
	int y;

	if (data->sprite_drawinfo->transformy > 0 && data->img->x > 0 &&
		data->img->x < data->screen_info->screenwidth &&
		data->sprite_drawinfo->transformy < data->sprites->buffer[data->img->x])
	{
		y = data->sprite_drawinfo->drawstarty;
		while (y < data->sprite_drawinfo->drawendy)
		{
			d = (int)((y) * 256 - data->screen_info->screenheight * 128 +
				data->sprite_drawinfo->spriteheight * 128);
			texy = ((d * data->img->sp_height) /
			data->sprite_drawinfo->spriteheight) / 256;
			if (mlx_get_color_value(data->mlx_ptr, data->img->sprite_data[(
					texx * 4 + data->img->sp_sl * texy) + 0]) != 0 &&
					mlx_get_color_value(data->mlx_ptr, data->img->sprite_data[(
					texx * 4 + data->img->sp_sl * texy) + 1]) != 0 &&
					mlx_get_color_value(data->mlx_ptr, data->img->sprite_data[(
					texx * 4 + data->img->sp_sl * texy) + 2] != 0))
				draw_sprite(data, y, texx, texy);
			y++;
		}
	}
}
