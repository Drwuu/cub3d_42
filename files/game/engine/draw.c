/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:09:37 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"
#include "../../../includes/tools.h"

t_color	get_cf_color(t_image texture, t_vec3 intersect)
{
	unsigned char	*pos;
	int				x;
	int				y;

	x = (intersect.x - (int)intersect.x) * texture.width;
	y = (intersect.y - (int)intersect.y) * texture.height;
	pos = (unsigned char *)texture.addr + y * texture.line_size + x * 4;
	if (x >= 0 && x < texture.width && y >= 0 && y < texture.height)
		return (ft_create_color(pos[3], pos[2], pos[1], pos[0]));
	return (ft_create_color(0, 0, 0, 0));
}

t_color	generic_get_color(t_image *texture, int x, int y)
{
	unsigned char	*pos;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (ft_create_color(0, 0, 0, 0));
	pos = (unsigned char *)texture->addr + y * texture->line_size + x * 4;
	return (ft_create_color(pos[3], pos[2], pos[1], pos[0]));
}

t_color	get_pixel_color(t_image texture, t_vec3 intersect, \
int is_depth)
{
	unsigned char	*pos;
	int				x;
	int				y;

	if (is_depth)
		x = (intersect.y - (int)intersect.y) * texture.width;
	else
		x = (intersect.x - (int)intersect.x) * texture.width;
	y = (1 - intersect.z) * texture.height;
	pos = (unsigned char *)texture.addr + y * texture.line_size + x * 4;
	if (x >= 0 && x < texture.width && y >= 0 && y < texture.height)
		return (ft_create_color(pos[3], pos[2], pos[1], pos[0]));
	return (ft_create_color(0, 0, 0, 0));
}

t_bool	draw_pixel(t_image image, int y, int x, t_color color)
{
	unsigned char	*pos;

	if (color.a == 255)
		return (FALSE);
	pos = (unsigned char *)image.addr + y * image.line_size + x * 4;
	pos[3] = color.a;
	pos[2] = color.r;
	pos[1] = color.g;
	pos[0] = color.b;
	return (TRUE);
}
