/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map3.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: axenth <axenth@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 22:51:15 by axenth        #+#    #+#                 */
/*   Updated: 2020/07/12 01:28:18 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <errors.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			get_map_size_2(t_data *data, char *line, int i, int s)
{
	if ((int)ft_strlen(line) > data->map_info->mapwidth)
		data->map_info->mapwidth = (int)ft_strlen(line);
	data->map_info->mapheight++;
	while (line[i] != '\0')
	{
		if (line[i] == '2')
			s++;
		i++;
	}
	return (s);
}

static void	handle_line_3(char *line, t_data *data, int l)
{
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (data->parser->we == 0)
			data->img->w_path = ft_substr(line, l, ft_strlen(line) - l);
		data->parser->we += 1;
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (data->parser->ea == 0)
			data->img->e_path = ft_substr(line, l, ft_strlen(line) - l);
		data->parser->ea += 1;
	}
	else if (ft_strncmp(line, "S", 1) == 0)
	{
		if (data->parser->sp == 0)
			data->img->sp_path = ft_substr(line, l, ft_strlen(line) - l);
		data->parser->sp += 1;
	}
}

void		handle_line_2(char *line, t_data *data, int l)
{
	char *temp;

	while (*line == ' ')
		line++;
	temp = ft_strtrim(line, " ");
	if (ft_strncmp(temp, "NO", 2) == 0)
	{
		if (data->parser->no == 0)
			data->img->n_path = ft_substr(temp, l, ft_strlen(temp) - l);
		data->parser->no += 1;
	}
	else if (ft_strncmp(temp, "SO", 2) == 0)
	{
		if (data->parser->so == 0)
			data->img->s_path = ft_substr(temp, l, ft_strlen(temp) - l);
		data->parser->so += 1;
	}
	else
	{
		handle_line_3(temp, data, l);
	}
	if (temp != NULL)
		free(temp);
}

static void	check_path_2(t_data *data)
{
	int fd[5];
	int i;

	i = 0;
	if (check_extension(data->img->n_path) == 0 ||
		check_extension(data->img->s_path) == 0 ||
		check_extension(data->img->e_path) == 0 ||
		check_extension(data->img->w_path) == 0 ||
		check_extension(data->img->sp_path) == 0)
		data->error = INVALID_MAP_FILE;
	fd[0] = open(data->img->n_path, O_RDONLY);
	fd[1] = open(data->img->e_path, O_RDONLY);
	fd[2] = open(data->img->s_path, O_RDONLY);
	fd[3] = open(data->img->w_path, O_RDONLY);
	fd[4] = open(data->img->sp_path, O_RDONLY);
	while (i < 5)
	{
		if (fd[i] == -1)
			data->error = TEX_EXIST;
		else
			close(fd[i]);
		i++;
	}
	if (check_extension(data->img->sp_path) == 2)
		data->img->sprite_png = 1;
}

void		check_path(t_data *data, int flag)
{
	int fd;

	if (flag == 1)
	{
		fd = open(data->map_path, O_RDONLY);
		if (fd == -1)
			data->error = MAP_EXIST;
		else
			close(fd);
	}
	else if (flag == 2)
	{
		check_path_2(data);
		if (check_extension(data->img->n_path) == 2)
			data->img->tex2_png = 1;
		if (check_extension(data->img->s_path) == 2)
			data->img->tex1_png = 1;
		if (check_extension(data->img->e_path) == 2)
			data->img->tex3_png = 1;
		if (check_extension(data->img->w_path) == 2)
			data->img->tex4_png = 1;
	}
	if (data->error != 0)
		handle_error(data);
}
