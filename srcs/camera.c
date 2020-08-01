/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 01:41:07 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/02 19:00:17 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_camera(t_data *data)
{
	data->camera->camerax = 2 * data->img->x /
						(float)data->screen_info->screenwidth - 1;
	data->camera->raydirx = data->player->dirx +
						data->player->planex * data->camera->camerax;
	data->camera->raydiry = data->player->diry +
						data->player->planey * data->camera->camerax;
	init_ray(data);
}
