/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:30:08 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 03:26:13 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	get_image_addr(t_vars *vr)
{
	vr->tex.we.img = mlx_xpm_file_to_image(vr->mlx, vr->map->we,
			&vr->tex.we.w, &vr->tex.we.h);
	vr->tex.no.img = mlx_xpm_file_to_image(vr->mlx, vr->map->no,
			&vr->tex.no.w, &vr->tex.no.h);
	vr->tex.so.img = mlx_xpm_file_to_image(vr->mlx, vr->map->so,
			&vr->tex.so.w, &vr->tex.so.h);
	vr->tex.ea.img = mlx_xpm_file_to_image(vr->mlx, vr->map->ea,
			&vr->tex.ea.w, &vr->tex.ea.h);
	if (!vr->tex.we.img || !vr->tex.no.img
		|| !vr->tex.so.img || !vr->tex.ea.img)
		exit(0);
	vr->tex.we.addr = mlx_get_data_addr(vr->tex.we.img,
			&vr->tex.we.bits_per_pixel, &vr->tex.we.line_length,
			&vr->tex.we.endian);
	vr->tex.no.addr = mlx_get_data_addr(vr->tex.no.img,
			&vr->tex.no.bits_per_pixel, &vr->tex.no.line_length,
			&vr->tex.no.endian);
	vr->tex.so.addr = mlx_get_data_addr(vr->tex.so.img,
			&vr->tex.so.bits_per_pixel, &vr->tex.so.line_length,
			&vr->tex.so.endian);
	vr->tex.ea.addr = mlx_get_data_addr(vr->tex.ea.img,
			&vr->tex.ea.bits_per_pixel, &vr->tex.ea.line_length,
			&vr->tex.ea.endian);
}
