/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_structs.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 00:09:50 by jlensing      #+#    #+#                 */
/*   Updated: 2020/07/03 23:07:04 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct			s_screen
{
	int					screenheight;
	int					screenwidth;
}						t_screen;

typedef struct			s_parser
{
	int					resolution;
	int					no;
	int					so;
	int					we;
	int					ea;
	int					sp;
	int					fl;
	int					ce;
	int					map;
	int					pl;
}						t_parser;

typedef struct			s_player
{
	float				posx;
	float				posy;
	float				dirx;
	float				diry;
	float				planex;
	float				planey;
	float				movespeed;
}						t_player;

typedef struct			s_keys
{
	int					key_w;
	int					key_a;
	int					key_s;
	int					key_d;
	int					key_arrow_left;
	int					key_arrow_right;
}						t_keys;

typedef struct			s_img
{
	int					bpp;
	int					size_line;
	int					endian;
	int					texheight;
	int					texwidth;
	void				*img;
	char				*n_path;
	char				*e_path;
	char				*s_path;
	char				*w_path;
	char				*sp_path;
	int					tex1_png;
	int					tex2_png;
	int					tex3_png;
	int					tex4_png;
	int					sprite_png;
	void				*tex1;
	void				*tex2;
	void				*tex3;
	void				*tex4;
	void				*sprite;
	char				*img_data;
	char				*tex1_data;
	char				*tex2_data;
	char				*tex3_data;
	char				*tex4_data;
	char				*sprite_data;
	int					tex1_sl;
	int					tex2_sl;
	int					tex3_sl;
	int					tex4_sl;
	int					sp_sl;
	int					tex1_width;
	int					tex1_height;
	int					tex2_width;
	int					tex2_height;
	int					tex3_width;
	int					tex3_height;
	int					tex4_width;
	int					tex4_height;
	int					sp_width;
	int					sp_height;
	int					x;
	int					y;
	int					textured;
	int					floor_red;
	int					floor_green;
	int					floor_blue;
	int					ceiling_red;
	int					ceiling_green;
	int					ceiling_blue;
}						t_img;

typedef struct			s_sprites
{
	int					amount;
	float				*buffer;
	float				*x;
	float				*y;
}						t_sprites;

typedef struct			s_camera
{
	float				camerax;
	float				raydirx;
	float				raydiry;
}						t_camera;

typedef struct			s_ray
{
	int					mapx;
	int					mapy;
	float				sidedistx;
	float				sidedisty;
	float				deltadistx;
	float				deltadisty;
	float				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	float				wallx;
	int					texx;
	int					texy;
	float				step;
	float				texpos;
}						t_ray;

typedef struct			s_sprite_drawinfo
{
	float				spritex;
	float				spritey;
	float				invdet;
	float				transformx;
	float				transformy;
	int					spritescreenx;
	int					spriteheight;
	int					drawstarty;
	int					drawendy;
	int					spritewidth;
	int					drawstartx;
	int					drawendx;
}						t_sprite_drawinfo;

typedef struct			s_drawinfo
{
	int					lineheight;
	int					drawstart;
	int					drawend;
}						t_drawinfo;

typedef struct			s_mapinfo
{
	int					**map;
	int					mapwidth;
	int					mapheight;
	int					start_reading;
}						t_map;

typedef struct			s_saftey
{
	int					map_count;
	int					inital_map;
	int					map_flag;
	int					sbuffer_flag;
	int					spos_flag;
	int					data_flag;
	int					init_failure;
	int					init_ptr;
	int					init_win;
	int					malloc_sprites;
	int					res_alloc;
}						t_safety;

typedef struct			s_data
{
	t_screen			*screen_info;
	void				*mlx_ptr;
	void				*mlx_win;
	t_player			*player;
	t_img				*img;
	t_camera			*camera;
	t_ray				*ray;
	t_drawinfo			*draw_info;
	t_sprite_drawinfo	*sprite_drawinfo;
	t_map				*map_info;
	int					error;
	t_keys				*key_info;
	t_sprites			*sprites;
	int					saveopt;
	char				*map_path;
	t_parser			*parser;
	t_safety			safety;
}						t_data;

#endif
