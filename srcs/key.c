/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:01:41 by jlensing      #+#    #+#                 */
/*   Updated: 2020/06/05 13:14:18 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <keys.h>

int		key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_info->key_w = 0;
	if (keycode == KEY_A)
		data->key_info->key_a = 0;
	if (keycode == KEY_S)
		data->key_info->key_s = 0;
	if (keycode == KEY_D)
		data->key_info->key_d = 0;
	if (keycode == KEY_ARROW_LEFT)
		data->key_info->key_arrow_left = 0;
	if (keycode == KEY_ARROW_RIGHT)
		data->key_info->key_arrow_right = 0;
	if (keycode == KEY_SHIFT)
		data->player->movespeed = 0.06;
	return (1);
}

int		key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_NUM_MINUS)
		data->img->textured *= -1;
	if (keycode == KEY_F12)
		screenshot("screenshot.bmp", data);
	if (keycode == KEY_W)
		data->key_info->key_w = 1;
	if (keycode == KEY_A)
		data->key_info->key_a = 1;
	if (keycode == KEY_S)
		data->key_info->key_s = 1;
	if (keycode == KEY_D)
		data->key_info->key_d = 1;
	if (keycode == KEY_ARROW_LEFT)
		data->key_info->key_arrow_left = 1;
	if (keycode == KEY_ARROW_RIGHT)
		data->key_info->key_arrow_right = 1;
	if (keycode == KEY_SHIFT)
		data->player->movespeed = 0.1;
	if (keycode == KEY_ESCAPE)
		exit_game(data);
	return (1);
}
