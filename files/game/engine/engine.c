/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:14:46 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/27 11:51:17 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"
#include "../../../includes/inputs.h"
#include "../../../includes/tools.h"

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

static t_image	init_user_mlx_image(t_cub3d *cub, int width, int height)
{
	t_image	image;

	image.image = mlx_new_image(cub->mlx, width, height);
	if (!image.image)
		error_manager(-1, cub, NULL, NULL);
	image.width = width;
	image.height = height;
	image.addr = \
		mlx_get_data_addr(image.image, &image.bits_per_pixel, \
		&image.line_size, &image.endian);
	if (!image.addr)
		error_manager(-1, cub, NULL, NULL);
	return (image);
}

static int	update(t_cub3d *cub)
{
	cub->engine.fps.frame++;
	time(&cub->engine.fps.current);
	cub->engine.time.end = ft_get_time();
	get_input(cub);
	multi_threading(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, \
	cub->engine.game_image.image, 0, 0);
	show_fps(cub);
	mlx_do_sync(cub->mlx);
	if (cub->settings.screen_shot)
	{
		take_screenshot(cub, "screenshot.bmp");
		cub->settings.screen_shot = FALSE;
	}
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
	cub->engine.game_image = init_user_mlx_image(cub, \
		cub->settings.window.width, cub->settings.window.height);
	update_sprite(cub);
	mlx_hook(cub->win, KEY_PRESS, 1L << 0, key_pressed, cub);
	mlx_hook(cub->win, KEY_RELEASE, 1L << 1, key_released, cub);
	mlx_hook(cub->win, DESTROY_NOTIFY, 1L << 0, leave_window, cub);
	mlx_do_key_autorepeatoff(cub->mlx);
	mlx_loop_hook(cub->mlx, update, cub);
	mlx_loop(cub->mlx);
}
