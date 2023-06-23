/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:36:04 by jduval            #+#    #+#             */
/*   Updated: 2023/06/23 17:01:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stddef.h>

static void	set_scaled_texture(int32_t *text, mlx_image_t *img);

int	resize_texture(t_data *data)
{
	int	i;
	mlx_image_t	*tmp;

	i = 0;
	while (i < 4)
	{
		tmp = mlx_texture_to_image(data->mlx, data->textures.texture[i]);
		if (tmp == NULL)
			return (1);
		if (mlx_resize_image(tmp, SIZE, SIZE) != true)
			return (1);
		set_scaled_texture(data->text[i], tmp);
		mlx_delete_image(data->mlx, tmp);	
		i++;
	}
	return (0);
}

static void	set_scaled_texture(int32_t *text, mlx_image_t *img)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	end = img->width * 4 * img->height;
	while (i <= end)
	{
		text[j] = color_pixel(img->pixels[i], img->pixels[i + 1],
				img->pixels[i + 2], img->pixels[i + 3]);
		i += 4;
		j++;
	}
	return ;
}
