/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 22:59:07 by jlensing      #+#    #+#                 */
/*   Updated: 2020/05/16 23:36:54 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

static float	calc_dist(t_data *data, float x, float y)
{
	float x1;
	float y1;

	x1 = data->player->posx - x;
	y1 = data->player->posy - y;
	return (x1 * x1 + y1 * y1);
}

static void		copy_results(t_data *data, float tempx[], float tempy[])
{
	int i;

	i = 0;
	while (i < data->sprites->amount)
	{
		data->sprites->x[i] = tempx[i];
		data->sprites->y[i] = tempy[i];
		i++;
	}
}

static void		sort_sprites_result(t_data *data, float tempx[], float tempy[],
									float dists[])
{
	int		i;
	int		i2;

	i2 = 1;
	while (i2)
	{
		i2 = 0;
		i = 0;
		while (i < data->sprites->amount - 1)
		{
			if (dists[i] - dists[i + 1] < 0)
			{
				ft_swap(&tempx[i], &tempx[i + 1]);
				ft_swap(&tempy[i], &tempy[i + 1]);
				ft_swap(&dists[i], &dists[i + 1]);
				i2 = 1;
			}
			i++;
		}
	}
	copy_results(data, tempx, tempy);
}

void			sort_sprites(t_data *data)
{
	float	tempx[data->sprites->amount];
	float	tempy[data->sprites->amount];
	float	dist[data->sprites->amount];
	int		i;

	i = 0;
	while (i < data->sprites->amount)
	{
		tempx[i] = data->sprites->x[i];
		tempy[i] = data->sprites->y[i];
		dist[i] = calc_dist(data, tempx[i], tempy[i]);
		i++;
	}
	sort_sprites_result(data, tempx, tempy, dist);
}
