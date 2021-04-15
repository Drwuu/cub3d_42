/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:54:38 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/11 10:47:35 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	show_fps(t_cub3d *cub)
{
	float	frame_time;
	
	if (difftime(cub->engine.fps.current, cub->engine.fps.start) >= 1.0)
	{
		time(&cub->engine.fps.start);
		cub->engine.fps.fps = ft_itoa((int)cub->engine.fps.frame);
		if (!cub->engine.fps.fps)
			error_manager(-1, cub, NULL, NULL);
		cub->engine.fps.join = ft_strjoin("FPS = ", cub->engine.fps.fps);
		if (!cub->engine.fps.join)
			error_manager(-1, cub, NULL, NULL);
		cub->engine.fps.frame = 0;
		if (cub->engine.fps.fps)
			free(cub->engine.fps.fps);
	}
	mlx_string_put(cub->mlx, cub->win, 10, 20, 0xFF0000, cub->engine.fps.join);
}
