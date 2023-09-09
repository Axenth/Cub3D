/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_images.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 23:04:10 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/12 01:16:21 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

#ifdef __APPLE__
static void	load_png_images_2(t_data *data)
{
	int img_width;
	int img_height;

	if (data->img->tex3_png == 1)
	{
		data->img->tex3 = mlx_png_file_to_image(data->mlx_ptr,
							data->img->e_path, &img_width, &img_height);
		data->img->tex3_width = img_width;
		data->img->tex3_height = img_height;
	}
	if (data->img->tex4_png == 1)
	{
		data->img->tex4 = mlx_png_file_to_image(data->mlx_ptr,
								data->img->w_path, &img_width, &img_height);
		data->img->tex4_width = img_width;
		data->img->tex4_height = img_height;
	}
	if (data->img->sprite_png == 1)
	{
		data->img->sprite = mlx_png_file_to_image(data->mlx_ptr,
								data->img->sp_path, &img_width, &img_height);
		data->img->sp_width = img_width;
		data->img->sp_height = img_height;
	}
	load_images_addr(data);
}

static void	load_png_images(t_data *data)
{
	int img_width;
	int img_height;

	if (data->img->tex1_png == 1)
	{
		data->img->tex1 = mlx_png_file_to_image(data->mlx_ptr,
								data->img->s_path, &img_width, &img_height);
		data->img->tex1_width = img_width;
		data->img->tex1_height = img_height;
	}
	if (data->img->tex2_png == 1)
	{
		data->img->tex2 = mlx_png_file_to_image(data->mlx_ptr,
								data->img->n_path, &img_width, &img_height);
		data->img->tex2_width = img_width;
		data->img->tex2_height = img_height;
	}
	load_png_images_2(data);
}
#elif __linux__
	static void load_png_images(t_data *data)
	{
		ft_printf("Unable to load png images on linux");
		load_images_addr(data);
	}
#endif

static void	load_xpm_images_2(t_data *data)
{
	int img_width;
	int img_height;

	if (data->img->tex3_png == 0)
	{
		data->img->tex3 = mlx_xpm_file_to_image(data->mlx_ptr,
							data->img->e_path, &img_width, &img_height);
		data->img->tex3_width = img_width;
		data->img->tex3_height = img_height;
	}
	if (data->img->tex4_png == 0)
	{
		data->img->tex4 = mlx_xpm_file_to_image(data->mlx_ptr,
								data->img->w_path, &img_width, &img_height);
		data->img->tex4_width = img_width;
		data->img->tex4_height = img_height;
	}
	if (data->img->sprite_png == 0)
	{
		data->img->sprite = mlx_xpm_file_to_image(data->mlx_ptr,
								data->img->sp_path, &img_width, &img_height);
		data->img->sp_width = img_width;
		data->img->sp_height = img_height;
	}
	load_png_images(data);
}

void		load_xpm_images(t_data *data)
{
	int img_width;
	int img_height;

	if (data->img->tex1_png == 0)
	{
		data->img->tex1 = mlx_xpm_file_to_image(data->mlx_ptr,
								data->img->s_path, &img_width, &img_height);
		data->img->tex1_width = img_width;
		data->img->tex1_height = img_height;
	}
	if (data->img->tex2_png == 0)
	{
		data->img->tex2 = mlx_xpm_file_to_image(data->mlx_ptr,
								data->img->n_path, &img_width, &img_height);
		data->img->tex2_width = img_width;
		data->img->tex2_height = img_height;
	}
	load_xpm_images_2(data);
}

void		init_png_parser_data(t_data *data)
{
	data->img->tex1_png = 0;
	data->img->tex2_png = 0;
	data->img->tex3_png = 0;
	data->img->tex4_png = 0;
	data->img->sprite_png = 0;
}
