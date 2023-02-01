/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:57:19 by atouati           #+#    #+#             */
/*   Updated: 2023/01/18 16:45:27 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	norm(t_vars *vr, t_ray *rays, int ray)
{
	cast_horz(vr, rays, ray);
	cast_vert(vr, rays, ray);
	distance(vr, rays, ray);
	wall_hieght(vr, rays, ray);
}

void	cast_ray(t_vars *vr, t_ray *rays, int ray, t_address *textures)
{
	int		i;

	norm(vr, rays, ray);
	i = rays->top_wall;
	if (!rays->wall_hit_virt)
		rays->offset_x = ((int)rays->wall_hit_x) % TILESISE;
	else
		rays->offset_x = ((int)rays->wall_hit_y) % TILESISE;
	rays->ray = ray;
	while (i < rays->bottom_wall)
	{
		if (rays->wall_hit_virt && rays->ray_right)
			put_wall_ea(vr, rays, i, textures);
		else if (rays->wall_hit_virt && rays->ray_left)
			put_wall_we(vr, rays, i, textures);
		else if (!rays->wall_hit_virt && rays->ray_down)
			put_wall_so(vr, rays, i, textures);
		else if (!rays->wall_hit_virt && rays->ray_up)
			put_wall_no(vr, rays, i, textures);
		i++;
	}
	drow_ceil_floo(rays, vr, ray);
}

t_ray	*cast_rays(t_vars *vr, t_ray *rays)
{
	int	ray;

	ray = 0;
	rays->ray_angle = vr->angle - ((60 * M_PI / 180) / 2);
	while (ray < vr->num_ray)
	{
		cast_ray(vr, rays, ray, &vr->tex);
		ray++;
		rays->ray_angle += (60 * M_PI / 180) / vr->num_ray;
	}
	return (rays);
}
