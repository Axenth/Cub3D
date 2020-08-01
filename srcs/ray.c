/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 12:46:50 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/03 19:02:42 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	decide_tex(t_data *data)
{
	if (0 > data->ray->stepx && data->ray->side == 0)
	{
		data->img->texwidth = data->img->tex1_width;
		data->img->texheight = data->img->tex1_height;
	}
	else if (0 <= data->ray->stepx && data->ray->side == 0)
	{
		data->img->texwidth = data->img->tex2_width;
		data->img->texheight = data->img->tex2_height;
	}
	if (data->ray->side == 1)
	{
		if (0 > data->ray->stepy)
		{
			data->img->texwidth = data->img->tex3_width;
			data->img->texheight = data->img->tex3_height;
		}
		else if (0 <= data->ray->stepy)
		{
			data->img->texwidth = data->img->tex4_width;
			data->img->texheight = data->img->tex4_height;
		}
	}
}

static void	calc_distance(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->perpwalldist = (data->ray->mapx - data->player->posx +
						(1 - data->ray->stepx) / 2) / data->camera->raydirx;
	else
		data->ray->perpwalldist = (data->ray->mapy - data->player->posy +
						(1 - data->ray->stepy) / 2) / data->camera->raydiry;
	decide_tex(data);
	calc_draw_one(data);
}

static void	calc_dda(t_data *data)
{
	while (data->ray->hit == 0)
	{
		if (data->ray->sidedistx < data->ray->sidedisty)
		{
			data->ray->sidedistx += data->ray->deltadistx;
			data->ray->mapx += data->ray->stepx;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidedisty += data->ray->deltadisty;
			data->ray->mapy += data->ray->stepy;
			data->ray->side = 1;
		}
		if (data->ray->mapx == data->map_info->mapheight ||
			data->ray->mapy == data->map_info->mapwidth)
		{
			data->ray->hit = 1;
			data->ray->mapx = data->map_info->mapheight - 1;
			data->ray->mapy = data->map_info->mapwidth - 1;
		}
		else if (data->map_info->map[data->ray->mapx][data->ray->mapy] > 0)
			data->ray->hit = 1;
	}
	calc_distance(data);
}

static void	calc_step(t_data *data)
{
	if (data->camera->raydirx < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidedistx = (data->player->posx - data->ray->mapx) *
													data->ray->deltadistx;
	}
	else
	{
		data->ray->stepx = 1;
		data->ray->sidedistx = (data->ray->mapx + 1.0 - data->player->posx) *
														data->ray->deltadistx;
	}
	if (data->camera->raydiry < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidedisty = (data->player->posy - data->ray->mapy) *
														data->ray->deltadisty;
	}
	else
	{
		data->ray->stepy = 1;
		data->ray->sidedisty = (data->ray->mapy + 1.0 - data->player->posy) *
														data->ray->deltadisty;
	}
	calc_dda(data);
}

void		init_ray(t_data *data)
{
	data->ray->mapx = (int)(data->player->posx);
	data->ray->mapy = (int)(data->player->posy);
	data->ray->deltadistx = fabs(1 / data->camera->raydirx);
	data->ray->deltadisty = fabs(1 / data->camera->raydiry);
	data->ray->hit = 0;
	calc_step(data);
}
