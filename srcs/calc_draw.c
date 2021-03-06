/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_draw.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: axenth <axenth@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 22:01:46 by axenth        #+#    #+#                 */
/*   Updated: 2020/07/03 20:23:08 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	calc_draw_two(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->wallx = data->player->posy + data->ray->perpwalldist *
														data->camera->raydiry;
	else
		data->ray->wallx = data->player->posx + data->ray->perpwalldist *
														data->camera->raydirx;
	data->ray->wallx -= floor(data->ray->wallx);
	data->ray->texx = (int)(data->ray->wallx * (float)(data->img->texwidth));
	if (data->ray->side == 0 && data->camera->raydirx > 0)
		data->ray->texx = data->img->texwidth - data->ray->texx - 1;
	if (data->ray->side == 1 && data->camera->raydiry < 0)
		data->ray->texx = data->img->texwidth - data->ray->texx - 1;
	data->ray->step = 1.0 * data->img->texheight / data->draw_info->lineheight;
	data->ray->texpos = (data->draw_info->drawstart -
				data->screen_info->screenheight / 2 +
				data->draw_info->lineheight / 2) * data->ray->step;
	set_sky(data);
}

void		calc_draw_one(t_data *data)
{
	data->draw_info->lineheight = (int)(data->screen_info->screenheight /
											data->ray->perpwalldist);
	data->draw_info->drawstart = -data->draw_info->lineheight / 2 +
											data->screen_info->screenheight / 2;
	if (data->draw_info->drawstart < 0)
		data->draw_info->drawstart = 0;
	data->draw_info->drawend = data->draw_info->lineheight / 2 +
											data->screen_info->screenheight / 2;
	if (data->draw_info->drawend >= data->screen_info->screenheight)
		data->draw_info->drawend = data->screen_info->screenheight - 1;
	calc_draw_two(data);
}
