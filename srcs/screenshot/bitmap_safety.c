/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap_safety.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:44:03 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/03 20:01:42 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <errors.h>
#include <stdlib.h>

void	handle_bmp_alloc_failure(t_data *data, unsigned char *header)
{
	free(header);
	data->error = ALLOC_FAILURE;
	handle_error(data);
}

void	bmp_info_header_zeroes(unsigned char *bmpinfoheader)
{
	bmpinfoheader[1] = 0;
	bmpinfoheader[2] = 0;
	bmpinfoheader[3] = 0;
	bmpinfoheader[13] = 0;
	bmpinfoheader[15] = 0;
}

void	handle_write_failure(t_data *data, unsigned char *bmpfileheader,
												unsigned char *bmpinfoheader)
{
	free(bmpfileheader);
	free(bmpinfoheader);
	data->error = WRITE_FAILED;
	handle_error(data);
}
