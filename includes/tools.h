/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:51:08 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 16:40:48 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# define THREAD_NB 8
# define PIXEL_DIVIDER 8

# include "cub3d.h"

void	take_screenshot(t_cub3d *cub, char *file_name);

#endif
