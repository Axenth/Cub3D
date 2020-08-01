/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safety2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 01:14:24 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/12 01:15:25 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <errors.h>
#include <stddef.h>

void	check_textures_corruption(t_data *data)
{
	if (data->img->tex1 == NULL || data->img->tex2 == NULL ||
		data->img->tex3 == NULL || data->img->tex4 == NULL ||
		data->img->sprite == NULL)
	{
		data->error = TEXTURE_CORRUPT;
		handle_error(data);
	}
}
