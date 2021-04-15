/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:14:46 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/11 11:26:12 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"
# define THREAD_NB 8

static void	multi_threading(t_cub3d *cub)
{
	t_thread	thread_datas[THREAD_NB];
	pthread_t	thread[THREAD_NB];
	int			ret;
	int			i;
	int			size;

	size = cub->settings.window.height / THREAD_NB;
	i = -1;
	while (++i < THREAD_NB)
	{
		thread_datas[i].cub = cub;
		thread_datas[i].start = size * i;
		thread_datas[i].end = size * (i + 1);
		ret = pthread_create(&thread[i], NULL, &draw_thread, &thread_datas[i]);
		if (ret < 0)
			error_manager(-2, cub, NULL, NULL);
	}
	i = -1;
	while (++i < THREAD_NB)
	{
		ret = pthread_join(thread[i], NULL);
		if (ret < 0)
			error_manager(-2, cub, NULL, NULL);
	}
}

static void	init_user_mlx_image(t_cub3d *cub)
{
	cub->engine.game_image.image = mlx_new_image(cub->mlx, \
	cub->settings.window.width, cub->settings.window.height);
	if (!cub->engine.game_image.image)
		error_manager(-1, cub, NULL, NULL);
	cub->engine.game_image.addr = \
	(unsigned int *)mlx_get_data_addr(cub->engine.game_image.image, \
	&cub->engine.game_image.bits_per_pixel, \
	&cub->engine.game_image.line_size, &cub->engine.game_image.endian);
	if (!cub->engine.game_image.addr)
		error_manager(-1, cub, NULL, NULL);
}

static int	update(t_cub3d *cub)
{
	cub->engine.fps.frame++;
	time(&cub->engine.fps.current);
	get_input(cub);
	if (cub->settings.multi_thread)
		multi_threading(cub);
	else
		draw(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->engine.game_image.image, 0, 0);
	show_fps(cub);
	mlx_do_sync(cub->mlx);
	return (0);
}

void	start(t_cub3d *cub)
{
	time(&cub->engine.fps.start);
	cub->win = mlx_new_window(cub->mlx, cub->settings.window.width, \
	cub->settings.window.height, "CUB3D");
	if (!cub->win)
		error_manager(-1, cub, NULL, NULL);
	init_rays(&cub);
	init_user_mlx_image(cub);
	mlx_hook(cub->win, KEY_PRESS, KEYPRESSMASK, key_pressed, cub);
	mlx_hook(cub->win, KEY_RELEASE, KEYRELEASEMASK, key_released, cub);
	mlx_loop_hook(cub->mlx, update, cub);
	mlx_loop(cub->mlx);
}
