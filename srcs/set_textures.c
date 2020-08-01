/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_textures.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: axenth <axenth@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 22:10:27 by axenth        #+#    #+#                 */
/*   Updated: 2020/07/14 22:03:06 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_tex_1(t_data *data)
{
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 0] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex2_data[(
		data->ray->texx * 4 + data->img->tex1_sl * data->ray->texy) + 0]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 1] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex2_data[(
		data->ray->texx * 4 + data->img->tex1_sl * data->ray->texy) + 1]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 2] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex2_data[(
		data->ray->texx * 4 + data->img->tex1_sl * data->ray->texy) + 2]);
}

void	set_tex_2(t_data *data)
{
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 0] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex1_data[(
		data->ray->texx * 4 + data->img->tex2_sl * data->ray->texy) + 0]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 1] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex1_data[(
		data->ray->texx * 4 + data->img->tex2_sl * data->ray->texy) + 1]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 2] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex1_data[(
		data->ray->texx * 4 + data->img->tex2_sl * data->ray->texy) + 2]);
}

void	set_tex_3(t_data *data)
{
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 0] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex3_data[(
		data->ray->texx * 4 + data->img->tex3_sl * data->ray->texy) + 0]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 1] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex3_data[(
		data->ray->texx * 4 + data->img->tex3_sl * data->ray->texy) + 1]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 2] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex3_data[(
		data->ray->texx * 4 + data->img->tex3_sl * data->ray->texy) + 2]);
}

void	set_tex_4(t_data *data)
{
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 0] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex4_data[(
		data->ray->texx * 4 + data->img->tex4_sl * data->ray->texy) + 0]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 1] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex4_data[(
		data->ray->texx * 4 + data->img->tex4_sl * data->ray->texy) + 1]);
	data->img->img_data[(data->img->x * 4 +
		data->img->size_line * data->img->y) + 2] =
		mlx_get_color_value(data->mlx_ptr, data->img->tex4_data[(
		data->ray->texx * 4 + data->img->tex4_sl * data->ray->texy) + 2]);
}
