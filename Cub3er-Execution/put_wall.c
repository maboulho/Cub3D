/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:39:47 by atouati           #+#    #+#             */
/*   Updated: 2023/01/14 01:40:29 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	put_wall_ea(t_vars *vr, t_ray *rays, int i, t_address *textures)
{
	char	*dst;

	rays->offset_y = (i + (rays->wall_hieght / 2) - (980 / 2))
		* ((double)textures->ea.h / rays->wall_hieght);
	dst = textures->ea.addr + (rays->offset_y * textures->ea.line_length
			+ rays->offset_x * (textures->ea.bits_per_pixel / 8));
	my_mlx_pixel_put(&vr->data, rays->ray, i, *(unsigned int *)dst);
}

void	put_wall_we(t_vars *vr, t_ray *rays, int i, t_address *textures)
{
	char	*dst;

	rays->offset_y = (i + (rays->wall_hieght / 2) - (980 / 2))
		* ((double)textures->we.h / rays->wall_hieght);
	dst = textures->we.addr + (rays->offset_y * textures->we.line_length
			+ rays->offset_x * (textures->we.bits_per_pixel / 8));
	my_mlx_pixel_put(&vr->data, rays->ray, i, *(unsigned int *)dst);
}

void	put_wall_so(t_vars *vr, t_ray *rays, int i, t_address *textures)
{
	char	*dst;

	rays->offset_y = (i + (rays->wall_hieght / 2) - (980 / 2))
		* ((double)textures->so.h / rays->wall_hieght);
	dst = textures->so.addr + (rays->offset_y * textures->so.line_length
			+ rays->offset_x * (textures->so.bits_per_pixel / 8));
	my_mlx_pixel_put(&vr->data, rays->ray, i, *(unsigned int *)dst);
}

void	put_wall_no(t_vars *vr, t_ray *rays, int i, t_address *textures)
{
	char	*dst;

	rays->offset_y = (i + (rays->wall_hieght / 2) - (980 / 2))
		* ((double)textures->no.h / rays->wall_hieght);
	dst = textures->no.addr + (rays->offset_y * textures->no.line_length
			+ rays->offset_x * (textures->no.bits_per_pixel / 8));
	my_mlx_pixel_put(&vr->data, rays->ray, i, *(unsigned int *)dst);
}
