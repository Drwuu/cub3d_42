/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/11 15:52:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INPUTS_H
# define INPUTS_H

# include "cub3d.h"

int		get_input(t_cub3d *cub);
int		key_pressed(int key, t_cub3d *cub);
int		key_released(int key, t_cub3d *cub);
void	rotate_player(t_cub3d *cub);
void	move_player(t_cub3d *cub);

#endif
