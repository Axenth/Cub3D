/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:54:34 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/12 01:15:35 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stddef.h>
#include <errors.h>

void	init_safety_data(t_data *data)
{
	data->safety.init_failure = 0;
	data->safety.init_ptr = 0;
	data->safety.init_win = 0;
}

void	init_data(t_data *data)
{
	init_parser_info(data);
	data->key_info->key_w = 0;
	data->key_info->key_a = 0;
	data->key_info->key_s = 0;
	data->key_info->key_d = 0;
	data->key_info->key_arrow_left = 0;
	data->key_info->key_arrow_right = 0;
	data->map_info->mapheight = 0;
	data->map_info->mapwidth = 0;
	data->map_info->start_reading = 0;
	data->sprites->amount = 0;
	data->img->textured = 1;
	data->safety.inital_map = 0;
	data->safety.map_flag = 0;
	data->safety.map_count = 0;
	data->safety.sbuffer_flag = 0;
	data->safety.spos_flag = 0;
	data->safety.malloc_sprites = 0;
	data->safety.res_alloc = 0;
	data->player->movespeed = 0.06;
	init_png_parser_data(data);
	read_map(data->map_path, data);
}

void	init_hooks(t_data *data)
{
	if (data->saveopt != 1)
	{
		mlx_hook(data->mlx_win, 2, 1L << 0, &key_handler, data);
		mlx_hook(data->mlx_win, 3, 1L << 1, &key_release, data);
		mlx_hook(data->mlx_win, 17, 0, exit_game, data);
	}
}

void	init_window(t_data *data)
{
	if (data->saveopt != 1)
	{
		data->mlx_win = mlx_new_window(data->mlx_ptr,
				data->screen_info->screenwidth, data->screen_info->screenheight,
																	"Cub3D");
		if (data->mlx_win == NULL)
			handle_init_error(data, 2);
	}
}

void	load_images_addr(t_data *data)
{
	int bpp;
	int size_line;
	int endian;

	check_textures_corruption(data);
	data->img->tex1_data = mlx_get_data_addr(data->img->tex1, &bpp, &size_line,
																	&endian);
	data->img->tex1_sl = size_line;
	data->img->tex2_data = mlx_get_data_addr(data->img->tex2, &bpp, &size_line,
																	&endian);
	data->img->tex2_sl = size_line;
	data->img->tex3_data = mlx_get_data_addr(data->img->tex3, &bpp, &size_line,
																	&endian);
	data->img->tex3_sl = size_line;
	data->img->tex4_data = mlx_get_data_addr(data->img->tex4, &bpp, &size_line,
																	&endian);
	data->img->tex4_sl = size_line;
	data->img->sprite_data = mlx_get_data_addr(data->img->sprite, &bpp,
														&size_line, &endian);
	data->img->sp_sl = size_line;
}
