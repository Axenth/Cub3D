/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:51:21 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/12 01:15:48 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <cub3d_structs.h>
# define ROTSPEED 0.06

void	init_data(t_data *data);
void	init_safety_data(t_data *data);
void	init_hooks(t_data *data);
void	init_window(t_data *data);
int		key_release(int keycode, t_data *data);
int		key_handler(int keycode, t_data *data);
int		move(t_data *data);
int		rotate(t_data *data);
void	init_ray(t_data *data);
void	init_camera(t_data *data);
void	set_sky(t_data *data);
void	read_map(char *path, t_data *data);
void	handle_error(t_data *data);
void	set_resolution(char *line, t_data *data);
void	set_floor_color(char *line, t_data *data);
void	set_ceiling_color(char *line, t_data *data);
void	set_player_pd(t_data *data, char dir);
void	screenshot(char *path, t_data *data);
void	check_map(t_data *data);
int		exit_game(t_data *data);
void	load_map_data(char *line, t_data *data);
int		is_map_line(char *line, t_data *data, int flag);
int		**fill_map_check(t_data *data, int **tempmap, int i, int j);
void	malloc_sprites(t_data *data, int amount);
void	calc_sprite_one(t_data *data, int i);
void	free_tempmap(t_data *data, int **tempmap);
void	calc_draw_one(t_data *data);
void	set_tex_1(t_data *data);
void	set_tex_2(t_data *data);
void	set_tex_3(t_data *data);
void	set_tex_4(t_data *data);
void	draw_sprites_loop(t_data *data, int texx);
void	turn_right(t_data *data, float olddirx, float oldplanex);
void	turn_left(t_data *data, float olddirx, float oldplanex);
int		get_map_size_2(t_data *data, char *line, int i, int s);
void	calc_fps(t_data *data);
void	check_args(t_data *data, int argv, char **argc);
void	init_parser_info(t_data *data);
int		check_file(t_data *data);
int		check_for_map(t_data *data);
void	handle_line_2(char *line, t_data *data, int l);
int		check_line_cmp(char *line);
void	check_path(t_data *data, int flag);
void	handle_temp_alloc_fail(t_data *data, int **tempmap, int i, int flag);
void	handle_gnl_error(t_data *data, int flag);
void	handle_map_error(t_data *data, int flag);
void	handle_bmp_alloc_failure(t_data *data, unsigned char *header);
void	handle_init_error(t_data *data, int flag);
void	bmp_info_header_zeroes(unsigned char *bmpinfoheader);
void	sort_sprites(t_data *data);
int		check_extension(char *path);
void	load_images_addr(t_data *data);
void	handle_write_failure(t_data *data, unsigned char *bmpfileheader,
												unsigned char *bmpinfoheader);
void	init_png_parser_data(t_data *data);
void	load_xpm_images(t_data *data);
void	check_textures_corruption(t_data *data);

#endif
