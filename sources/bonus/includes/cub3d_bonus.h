/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:20 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/29 13:41:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "type_bonus.h"

//-------------PARSING---------------//
//map_get_info
int		get_texture_info(char **dataline,
			char *card, t_data *data, int index_tab);
int		get_color_info(char **dataline, char place, t_data *data);
int		get_map(int file_fd, t_data *data);
//file : content_verif.c
int		valid_extension(char *path, char *extension);
int		valid_color(int red, int green, int blue);
int		valid_texture(char *path_texture);
//file : map_verif.c
int		simple_verify_map(char **map);
int		is_wall_surround(char **map);
//file : utils_map.c
char	*gnl_skip_void(int fd_file);
int		len_dbl_tab(char **tab);
int		len_string(char *str);
int		print_error_map(int type_error);
void	clean_texture_nb(t_texture *textures, int nb_textures);
//file : load_map.c
int		load_file(char **argv, t_data *data);
//file : verify.c
void	verify_init(int *verify);
void	delete_textures(t_data *data, int *verify);
int		verif_verify(t_data *data, int *verify);
//file : resize_texture.c
int		resize_texture(t_data *data);
void	free_textures(uint32_t **textures);

//-------------INITIALIZATION---------------//
//file : init_player.c
void	init_player(t_player *player, t_data *data);
//file : init_images.c
int		init_images(t_data *data);

//-------------DRAW---------------//
//file : draw_map.c
void	draw_map(t_data *data);
//file : draw_player.c
void	draw_player(mlx_image_t *img, t_player *player, int unit, int flag);
//file : draw_line.c
void	draw_line(mlx_image_t *img, float *pos, int32_t color);
void	draw_pov(t_data *data, t_player *player, int flag);
//file : draw_utils.c
int32_t	color_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
void	reset_map(mlx_image_t *img);
//file : draw_background.c
void	draw_background_ceiling(t_data *data);
void	draw_background_floor(t_data *data);
//file : render_image.c
int		render_start(t_data *data);

//-------------RAYCASTING---------------//
//file : raycasting.c
int		raycasting(t_data *data, t_player *player);
//file : raycasting_utils.c
void	process_ndist(float *n_dist, float *u_vector, float unit);
void	first_dist(t_raytool *rtool, float *pos, float unit, float alpha);
void	process_uvector(float alpha, float *u_vector);
bool	special_angle_uvector(float alpha, float *u_vector);
//file : result_ray.c
void	set_texture(t_ray *ray, int side, float *u_vector);
float	set_perpdist(t_data *data, t_raytool *rtool);
void	set_coord(t_ray *ray, t_raytool *rtool, float *pos, float alpha);
//file : texturing.c
void	draw_texture(t_data *data, t_ray *ray);

//-------------MOVEMENTS---------------//
//file : move_player.c
void	move_backward_forward(t_data *data, t_player *player, t_dir dir);
//file : shift_player.c
void	move_left_right(t_data *data, t_player *player, t_dir dir);
//file : wall_collision.c
bool	check_collide(t_data *data, float x, float y);
//file : rotate_player.c
void	rotate_player(t_player *player, t_dir dir);

//-------------INPUT---------------//
//file : key_functions.c
void	user_inputs(void *param);
void	modifier_inputs(mlx_key_data_t keydata, void *param);

#endif
