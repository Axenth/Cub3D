/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verification.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/05 01:31:10 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/12 01:18:03 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

int		check_line_cmp(char *line)
{
	while (*line == ' ')
		line++;
	if (((ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
		ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0) &&
		line[2] == ' ') || (ft_strncmp(line, "S", 1) == 0 && line[1] == ' '))
		return (1);
	if (ft_strncmp(line, "R", 1) == 0 && ft_str_only_contains(line + 1,
													"0123456789 ") == 1)
		return (2);
	if (ft_strncmp(line, "F", 1) == 0 && ft_str_only_contains(line + 1,
													"0123456789, ") == 1)
		return (3);
	if (ft_strncmp(line, "C", 1) == 0 && ft_str_only_contains(line + 1,
													"0123456789, ") == 1)
		return (4);
	return (0);
}

int		check_for_map(t_data *data)
{
	if (data->parser->resolution != 1)
		return (0);
	if (data->parser->no != 1)
		return (0);
	if (data->parser->so != 1)
		return (0);
	if (data->parser->we != 1)
		return (0);
	if (data->parser->ea != 1)
		return (0);
	if (data->parser->sp != 1)
		return (0);
	if (data->parser->fl != 1)
		return (0);
	if (data->parser->ce != 1)
		return (0);
	if (data->map_info->start_reading != 1)
		return (0);
	return (1);
}

void	init_parser_info(t_data *data)
{
	data->parser->resolution = 0;
	data->parser->no = 0;
	data->parser->so = 0;
	data->parser->we = 0;
	data->parser->ea = 0;
	data->parser->sp = 0;
	data->parser->fl = 0;
	data->parser->ce = 0;
	data->parser->map = 0;
}

int		check_file(t_data *data)
{
	if (data->parser->resolution != 1)
		return (0);
	if (data->parser->no != 1)
		return (0);
	if (data->parser->so != 1)
		return (0);
	if (data->parser->we != 1)
		return (0);
	if (data->parser->ea != 1)
		return (0);
	if (data->parser->sp != 1)
		return (0);
	if (data->parser->fl != 1)
		return (0);
	if (data->parser->ce != 1)
		return (0);
	if (data->parser->map != 1)
		return (0);
	return (1);
}

int		check_extension(char *path)
{
	if ((path[ft_strlen(path) - 3] == 'X' || path[ft_strlen(path) - 3] == 'x')
	&& (path[ft_strlen(path) - 2] == 'P' || path[ft_strlen(path) - 2] == 'p')
	&& (path[ft_strlen(path) - 1] == 'M' || path[ft_strlen(path) - 1] == 'm'))
		return (1);
	if ((path[ft_strlen(path) - 3] == 'P' || path[ft_strlen(path) - 3] == 'p')
	&& (path[ft_strlen(path) - 2] == 'N' || path[ft_strlen(path) - 2] == 'n')
	&& (path[ft_strlen(path) - 1] == 'G' || path[ft_strlen(path) - 1] == 'g'))
		return (2);
	return (0);
}
