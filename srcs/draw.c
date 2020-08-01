/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 01:41:21 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/03 19:09:37 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	set_pixel(t_data *data, unsigned int red,
					unsigned int green, unsigned int blue)
{
	data->img->img_data[data->img->x * 4 +
		data->img->size_line * data->img->y] = red;
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 1] = green;
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 2] = blue;
}

static void	draw_sprites(t_data *data)
{
	int i;
	int texx;

	i = 0;
	sort_sprites(data);
	while (i < data->sprites->amount)
	{
		calc_sprite_one(data, i);
		if (data->img->x >= data->sprite_drawinfo->drawstartx &&
			data->img->x <= data->sprite_drawinfo->drawendx)
		{
			if (data->sprite_drawinfo->spritewidth == 0)
				data->sprite_drawinfo->spritewidth = 1;
			texx = (int)(256 * (data->img->x -
				(-data->sprite_drawinfo->spritewidth / 2 +
				data->sprite_drawinfo->spritescreenx)) * data->img->sp_width /
				data->sprite_drawinfo->spritewidth) / 256;
			draw_sprites_loop(data, texx);
		}
		i++;
	}
}

static void	draw_floor(t_data *data)
{
	while (data->draw_info->drawstart < data->screen_info->screenheight)
	{
		data->img->y = data->draw_info->drawstart;
		set_pixel(data, data->img->floor_blue,
				data->img->floor_green, data->img->floor_red);
		data->draw_info->drawstart++;
	}
	data->sprites->buffer[data->img->x] = data->ray->perpwalldist;
	draw_sprites(data);
}

static void	draw_objs(t_data *data)
{
	while (data->draw_info->drawstart < data->draw_info->drawend)
	{
		data->ray->texy = (int)data->ray->texpos & (data->img->texheight - 1);
		data->ray->texpos += data->ray->step;
		data->img->y = data->draw_info->drawstart;
		if (data->img->textured == 1)
		{
			if (data->map_info->map[data->ray->mapx][data->ray->mapy] >= 1)
			{
				if (0 > data->ray->stepx && data->ray->side == 0)
					set_tex_1(data);
				else if (0 <= data->ray->stepx && data->ray->side == 0)
					set_tex_2(data);
				if (data->ray->side == 1)
				{
					if (0 > data->ray->stepy)
						set_tex_3(data);
					else if (0 <= data->ray->stepy)
						set_tex_4(data);
				}
			}
		}
		data->draw_info->drawstart++;
	}
	draw_floor(data);
}

void		set_sky(t_data *data)
{
	int sky;

	sky = 0;
	while (sky < data->draw_info->drawstart)
	{
		data->img->y = sky;
		set_pixel(data, data->img->ceiling_blue,
					data->img->ceiling_green, data->img->ceiling_red);
		sky++;
	}
	draw_objs(data);
}
