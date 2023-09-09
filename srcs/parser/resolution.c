/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resolution.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 01:36:40 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/22 18:38:10 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <errors.h>
#include <libft.h>
#include <stdlib.h>

static void	safety(t_data *data)
{
	int x;
	int y;

	if (data->screen_info->screenwidth == 0 ||
		data->screen_info->screenheight == 0)
	{
		data->error = INVALID_MAP_FILE;
		handle_error(data);
	}
	#ifdef __APPLE__
	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	#elif __linux__
	x = 3840;
	y = 2160;
	#endif
	if (data->screen_info->screenwidth < 0 && data->saveopt != 1)
		data->screen_info->screenwidth = x;
	if (data->screen_info->screenheight < 0 && data->saveopt != 1)
		data->screen_info->screenheight = y;
}

static void	set_resolution3(char *line, t_data *data)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	temp = ft_strdup(line + i);
	if (temp == NULL)
	{
		data->safety.res_alloc = 1;
		data->error = ALLOC_FAILURE;
		handle_error(data);
	}
	temp2 = temp;
	while (*temp != ' ')
		temp++;
	i = ft_strlen(temp);
	if (temp[i] == ' ')
		while (temp[i] != ' ' && i > 0)
			i--;
	temp[i + 1] = '\0';
	data->screen_info->screenheight = ft_atoi(ft_strnstr(temp,
														"\0", ft_strlen(temp)));
	free(temp2);
}

static void	mlx_max_res(t_data *data)
{
	if (data->saveopt == 1)
	{
		if (data->screen_info->screenwidth > 15360)
			data->screen_info->screenwidth = 15360;
		if (data->screen_info->screenheight > 8640)
			data->screen_info->screenheight = 8640;
	}
}

static void	set_resolution2(char *line, t_data *data)
{
	char	*temp;
	int		x;
	int		y;

	while (*line == ' ')
		line++;
	temp = ft_strchr(line, ' ');
	data->screen_info->screenwidth = ft_atoi(temp);
	set_resolution3(line, data);
	safety(data);
	#ifdef __APPLE__
	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	#elif __linux__
	x = 3840;
	y = 2160;
	#endif
	if (data->screen_info->screenwidth > x && data->saveopt != 1)
		data->screen_info->screenwidth = x;
	if (data->screen_info->screenheight > y && data->saveopt != 1)
		data->screen_info->screenheight = y;
	data->sprites->buffer = malloc(sizeof(float)
							* data->screen_info->screenwidth);
	if (data->sprites->buffer == NULL)
	{
		data->safety.sbuffer_flag = 1;
		data->error = ALLOC_FAILURE;
		handle_error(data);
	}
	mlx_max_res(data);
}

void		set_resolution(char *line, t_data *data)
{
	if (ft_strcontains(line, "-") == 1)
	{
		data->error = INVALID_MAP_FILE;
		handle_error(data);
	}
	if (data->parser->resolution == 0)
		set_resolution2(line, data);
	data->parser->resolution += 1;
}
