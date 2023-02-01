/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_horz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:49:03 by atouati           #+#    #+#             */
/*   Updated: 2023/01/15 05:16:49 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	check_horz(t_vars *vr, t_ray *rays, int ray)
{
	double	nexthorztouchx;
	double	nexthorztouchy;

	(void)ray;
	nexthorztouchx = rays->xintercept;
	nexthorztouchy = rays->yintercept;
	while ((nexthorztouchx >= TILESISE && nexthorztouchx <= TILESISE
			* vr->num_col && nexthorztouchy >= TILESISE
			&& nexthorztouchy <= TILESISE * vr->num_row))
	{
		if (rays->ray_up)
			vr->flag = -1;
		if (has_wall(nexthorztouchx, nexthorztouchy + vr->flag, vr))
		{
			rays->foundhorzwallhit = 1;
			rays->horzwallhitx = nexthorztouchx;
			rays->horzwallhity = nexthorztouchy;
			break ;
		}
		else
		{
			nexthorztouchx += rays->xstep;
			nexthorztouchy += rays->ystep;
		}
	}
}

void	cast_horz(t_vars *vr, t_ray *rays, int ray)
{
	init(rays, ray);
	rays->foundhorzwallhit = 0;
	rays->yintercept = floor(vr->y / TILESISE) * TILESISE;
	if (rays->ray_down)
		rays->yintercept += TILESISE;
	else
		rays->yintercept += 0;
	rays->xintercept = vr->x + (rays->yintercept - vr->y)
		/ tan(rays->ray_angle);
	rays->ystep = TILESISE;
	if (rays->ray_up)
		rays->ystep *= -1;
	else
		rays->ystep *= 1;
	rays->xstep = TILESISE / tan(rays->ray_angle);
	if (rays->ray_left && rays->xstep > 0)
		rays->xstep *= -1;
	else
		rays->xstep *= 1;
	if (rays->ray_right && rays->xstep < 0)
		rays->xstep *= -1;
	else
		rays->xstep *= 1;
	vr->flag = 0;
	check_horz(vr, rays, ray);
}
