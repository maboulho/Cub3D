/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:49:58 by atouati           #+#    #+#             */
/*   Updated: 2023/01/15 05:18:16 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

double	get_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void	distance_norm(double vert_distance, double horz_distance, t_ray *rays)
{
	if (vert_distance < horz_distance)
	{
		rays->wall_hit_x = rays->vertwallhitx;
		rays->wall_hit_y = rays->vertwallhity;
		rays->distance = vert_distance;
		rays->wall_hit_virt = 1;
	}
	else
	{
		rays->wall_hit_x = rays->horzwallhitx;
		rays->wall_hit_y = rays->horzwallhity;
		rays->distance = horz_distance;
		rays->wall_hit_virt = 0;
	}
}

void	distance(t_vars *vr, t_ray *rays, int ray)
{
	double	horz_distance;
	double	vert_distance;

	(void)ray;
	if (rays->foundhorzwallhit && (rays->horzwallhitx
			|| rays->horzwallhity))
		horz_distance = get_distance(vr->x, vr->y, rays->horzwallhitx,
				rays->horzwallhity);
	else
		horz_distance = INT_MAX;
	if (rays->foundvertwallhit && (rays->vertwallhitx
			|| rays->vertwallhity))
		vert_distance = get_distance(vr->x, vr->y, rays->vertwallhitx,
				rays->vertwallhity);
	else
		vert_distance = INT_MAX;
	distance_norm(vert_distance, horz_distance, rays);
}
