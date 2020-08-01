/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 02:15:12 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/03 23:28:22 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <cub3d.h>
#include <errors.h>
#include <libft.h>

static void	malloc_data(t_data *data)
{
	data->safety.data_flag = 0;
	data->screen_info = malloc(sizeof(t_screen));
	data->img = malloc(sizeof(t_img));
	data->camera = malloc(sizeof(t_camera));
	data->ray = malloc(sizeof(t_ray));
	data->draw_info = malloc(sizeof(t_drawinfo));
	data->sprite_drawinfo = malloc(sizeof(t_sprite_drawinfo));
	data->map_info = malloc(sizeof(t_map));
	data->key_info = malloc(sizeof(t_keys));
	data->sprites = malloc(sizeof(t_sprites));
	data->parser = malloc(sizeof(t_parser));
	if (data->screen_info == NULL || data->img == NULL ||
		data->camera == NULL || data->ray == NULL || data->draw_info == NULL ||
		data->map_info == NULL || data->sprite_drawinfo == NULL ||
		data->key_info == NULL || data->sprites == NULL || data->parser == NULL)
	{
		data->error = ALLOC_FAILURE;
		data->safety.data_flag = 1;
		handle_error(data);
	}
	init_data(data);
}

static void	init_images(t_data *data)
{
	int bbp;
	int size_line;
	int endian;

	data->img->img = mlx_new_image(data->mlx_ptr,
			data->screen_info->screenwidth, data->screen_info->screenheight);
	data->img->img_data = mlx_get_data_addr(data->img->img, &bbp, &size_line,
																	&endian);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->img->img);
	data->img->size_line = size_line;
	data->img->bpp = bbp;
	data->img->endian = endian;
}

int			loop(t_data *data)
{
	int x;

	x = 0;
	move(data);
	rotate(data);
	if (data->error != 0)
		handle_error(data);
	while (x < data->screen_info->screenwidth)
	{
		data->img->x = x;
		init_camera(data);
		x++;
	}
	if (data->saveopt != 1)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0,
																			0);
	if (data->saveopt == 1)
	{
		screenshot("save.bmp", data);
		exit_game(data);
	}
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, data->mlx_win);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, data->mlx_win);
	return (1);
}

int			main(int argv, char **argc)
{
	t_data		*data;
	t_player	player;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		handle_init_error(data, 0);
	check_args(data, argv, argc);
	data->error = 0;
	data->player = &player;
	malloc_data(data);
	data->mlx_ptr = mlx_init();
	init_safety_data(data);
	if (data->mlx_ptr == NULL)
		handle_init_error(data, 1);
	init_window(data);
	check_map(data);
	load_xpm_images(data);
	init_images(data);
	init_hooks(data);
	mlx_loop_hook(data->mlx_ptr, loop, data);
	mlx_loop(data->mlx_ptr);
}
