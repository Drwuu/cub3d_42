/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 18:22:13 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		put_pixel2(t_frame *frame, int x, int y, int color)
{
	char	*pixel;

	pixel = frame->addr + (y * frame->line_size + x * \
	(frame->bits_per_pixel / 8));
	((unsigned int *)pixel)[0] = color;
}

void			put_pixel(t_cub3d *cub, int x, int y)
{
	t_frame	frame;

	frame.frame = mlx_new_image(cub->mlx, cub->window.width, \
	cub->window.height);
	if (!frame.frame)
		error_manager(-1, cub, NULL, NULL);
	frame.addr = mlx_get_data_addr(frame.frame, &frame.bits_per_pixel, \
	&frame.line_size, &frame.endian);
	if (!frame.addr)
		error_manager(-1, cub, NULL, NULL);
	put_pixel2(&frame, cub->window.width / 2, cub->window.height / 2, \
	0x00FF0000);
}
