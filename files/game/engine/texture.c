/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:40:35 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/08 15:36:09 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_image	get_texture(t_cub3d *cub, char *text_path)
{
	t_image	texture;

	texture.image = mlx_xpm_file_to_image(cub->mlx, text_path, \
	&texture.width, &texture.height);
	if (!texture.image)
		error_manager(31, cub, NULL, NULL);
	texture.addr = (unsigned int *)mlx_get_data_addr(texture.image, \
	&texture.bits_per_pixel, \
	&texture.line_size, &texture.endian);
	if (!texture.addr)
		error_manager(31, cub, NULL, NULL);
	return (texture);
}
