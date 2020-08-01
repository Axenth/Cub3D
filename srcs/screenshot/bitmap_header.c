/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap_header.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 15:31:57 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/22 13:16:14 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <cub3d.h>
#include <errors.h>
#include <fcntl.h>
#include <stdlib.h>

/*
** 2 Bytes - Identifier
** 4 Bytes - File size in bytes
** 2 Bytes - Reserved
** 2 Bytes - Reserved
** 4 Bytes - Offset of the the byte where the image data starts
*/

static unsigned char		*init_file_header(t_data *data, int filesize)
{
	unsigned char *bmpfileheader;

	bmpfileheader = malloc(sizeof(char) * 14);
	if (bmpfileheader == NULL)
	{
		data->error = ALLOC_FAILURE;
		handle_error(data);
	}
	bmpfileheader[0] = 'B';
	bmpfileheader[1] = 'M';
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	bmpfileheader[6] = 0;
	bmpfileheader[7] = 0;
	bmpfileheader[8] = 0;
	bmpfileheader[9] = 0;
	bmpfileheader[10] = 54;
	bmpfileheader[11] = 0;
	bmpfileheader[12] = 0;
	bmpfileheader[13] = 0;
	return (bmpfileheader);
}

/*
** 4 Bytes - Size of the info header = 40 Bytes
** 4 Bytes - Horizontal width of the bitmap in pixels
** 4 Bytes - Vertical height of the bitmap in pixels
** 2 Bytes - Number of Planes = 1
** 2 Bytes - Bits per Pixel used to store color info. 24 = 24bit RGB 16M colors
** 4 Bytes - Compression = unused
** 4 Bytes - Image size compressed = unused
** 4 Bytes - XpixelsPerM compressed = unused
** 4 Bytes - YpixelsPerM compressed = unused
** 4 Bytes - Acutal colors used = unused
** 4 Bytes - Important colors 0 = all
*/

static unsigned char		*init_info_header(t_data *data,
												int i, unsigned char *header)
{
	unsigned char *bmpinfoheader;

	bmpinfoheader = malloc(sizeof(char) * 40);
	if (bmpinfoheader == NULL)
		handle_bmp_alloc_failure(data, header);
	bmp_info_header_zeroes(bmpinfoheader);
	bmpinfoheader[0] = 40;
	bmpinfoheader[4] = (unsigned char)(data->screen_info->screenwidth);
	bmpinfoheader[5] = (unsigned char)(data->screen_info->screenwidth >> 8);
	bmpinfoheader[6] = (unsigned char)(data->screen_info->screenwidth >> 16);
	bmpinfoheader[7] = (unsigned char)(data->screen_info->screenwidth >> 24);
	bmpinfoheader[8] = (unsigned char)(data->screen_info->screenheight);
	bmpinfoheader[9] = (unsigned char)(data->screen_info->screenheight >> 8);
	bmpinfoheader[10] = (unsigned char)(data->screen_info->screenheight >> 16);
	bmpinfoheader[11] = (unsigned char)(data->screen_info->screenheight >> 24);
	bmpinfoheader[12] = 1;
	bmpinfoheader[14] = 24;
	while (i < 40)
	{
		bmpinfoheader[i] = 0;
		i++;
	}
	return (bmpinfoheader);
}

static int					write_rgb(int fd, t_data *data, int x, int y)
{
	int wr;
	int ret;

	ret = (4 - (data->screen_info->screenwidth * 3) % 4) % 4;
	while (y < data->screen_info->screenwidth)
	{
		wr = write(fd, &data->img->img_data[(x * data->img->size_line
										+ y * (data->img->bpp / 8)) + 0], 1);
		if (wr < 0)
			return (-1);
		wr = write(fd, &data->img->img_data[(x * data->img->size_line
										+ y * (data->img->bpp / 8)) + 1], 1);
		if (wr < 0)
			return (-1);
		wr = write(fd, &data->img->img_data[(x * data->img->size_line
										+ y * (data->img->bpp / 8)) + 2], 1);
		if (wr < 0)
			return (-1);
		y++;
	}
	if (ret > 0)
		wr = write(fd, "\x00\x00\x00", ret);
	if (wr < 0)
		return (-1);
	return (0);
}

static void					save_bitmap(int fd, t_data *data)
{
	int				filesize;
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;
	int				x;

	filesize = 54 + 3 * data->screen_info->screenwidth *
										data->screen_info->screenheight;
	bmpfileheader = init_file_header(data, filesize);
	bmpinfoheader = init_info_header(data, 16, bmpfileheader);
	if (write(fd, bmpfileheader, 14) < 0 || write(fd, bmpinfoheader, 40) < 0)
		handle_write_failure(data, bmpfileheader, bmpinfoheader);
	x = data->screen_info->screenheight - 1;
	while (x >= 0)
	{
		if (write_rgb(fd, data, x, 0) < 0)
			handle_write_failure(data, bmpfileheader, bmpinfoheader);
		x--;
	}
	free(bmpfileheader);
	free(bmpinfoheader);
}

void						screenshot(char *path, t_data *data)
{
	int fd;

	fd = open(path, O_RDWR | O_APPEND | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		data->error = FD_FAILED;
		return ;
	}
	save_bitmap(fd, data);
	close(fd);
}
