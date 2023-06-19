/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:44:08 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 18:34:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

void	esc_input(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	movement_key(data);
	return ;
}

static void	mouse_control(t_data *data)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	mlx_set_mouse_pos(data->mlx, WIDTH / 2 , data->player.height);
	if (x > data->player.mouse_x)
		rotate_player(data, &data->player, RIGHTWARD);
	else if (x < data->player.mouse_x)
		rotate_player(data, &data->player, LEFTWARD);
}

void	movement_key(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) == true)
		move_backward_forward(data, &data->player, FORWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) == true)
		move_backward_forward(data, &data->player, BACKWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) == true)
		move_left_right(data, &data->player, LEFTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) == true)
		move_left_right(data, &data->player, RIGHTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(data, &data->player, RIGHTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == true)
		rotate_player(data, &data->player, LEFTWARD);
	mouse_control(data);
	raycasting(data, &data->player);
	return ;
}
