/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 02:16:02 by jlensing      #+#    #+#                 */
/*   Updated: 2020/06/16 11:33:32 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	move_right(t_data *data)
{
	float lookdirx;
	float lookdiry;

	lookdirx = data->player->diry;
	lookdiry = data->player->dirx;
	if (data->map_info->map
		[(int)(data->player->posx + lookdirx * data->player->movespeed)]
		[(int)(data->player->posy)] == 0)
		data->player->posx += lookdirx * data->player->movespeed;
	if (data->map_info->map
		[(int)(data->player->posx)]
		[(int)(data->player->posy - lookdiry * data->player->movespeed)] == 0)
		data->player->posy -= lookdiry * data->player->movespeed;
}

static void	move_left(t_data *data)
{
	float lookdirx;
	float lookdiry;

	lookdirx = data->player->diry;
	lookdiry = data->player->dirx;
	if (data->map_info->map
		[(int)(data->player->posx - lookdirx * data->player->movespeed)]
		[(int)(data->player->posy)] == 0)
		data->player->posx -= lookdirx * data->player->movespeed;
	if (data->map_info->map
		[(int)(data->player->posx)]
		[(int)(data->player->posy + lookdiry * data->player->movespeed)] == 0)
		data->player->posy += lookdiry * data->player->movespeed;
}

int			move(t_data *data)
{
	if (data->key_info->key_w == 1)
	{
		if (data->map_info->map[(int)(data->player->posx + data->player->dirx *
				data->player->movespeed)][(int)(data->player->posy)] == 0)
			data->player->posx += data->player->dirx * data->player->movespeed;
		if (data->map_info->map[(int)(data->player->posx)]
				[(int)(data->player->posy + data->player->diry *
				data->player->movespeed)] == 0)
			data->player->posy += data->player->diry * data->player->movespeed;
	}
	if (data->key_info->key_a == 1)
		move_left(data);
	if (data->key_info->key_s == 1)
	{
		if (data->map_info->map[(int)(data->player->posx - data->player->dirx *
				data->player->movespeed)][(int)(data->player->posy)] == 0)
			data->player->posx -= data->player->dirx * data->player->movespeed;
		if (data->map_info->map[(int)(data->player->posx)][(int)
				(data->player->posy - data->player->diry *
				data->player->movespeed)] == 0)
			data->player->posy -= data->player->diry * data->player->movespeed;
	}
	if (data->key_info->key_d)
		move_right(data);
	return (1);
}

int			rotate(t_data *data)
{
	float olddirx;
	float oldplanex;

	olddirx = data->player->dirx;
	oldplanex = data->player->planex;
	if (data->key_info->key_arrow_right == 1 &&
					data->key_info->key_arrow_left == 0)
		turn_right(data, olddirx, oldplanex);
	if (data->key_info->key_arrow_left == 1 &&
					data->key_info->key_arrow_right == 0)
		turn_left(data, olddirx, oldplanex);
	return (1);
}
