/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:47:40 by atouati           #+#    #+#             */
/*   Updated: 2023/01/15 05:17:37 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	check_vert(t_vars *vr, t_ray *rays, int ray)
{
	double	nextverttouchx;
	double	nextverttouchy;

	(void)ray;
	nextverttouchx = rays->xintercept;
	nextverttouchy = rays->yintercept;
	while ((nextverttouchx >= TILESISE && nextverttouchx <= TILESISE
			* vr->num_col && nextverttouchy >= TILESISE
			&& nextverttouchy <= TILESISE * vr->num_row))
	{
		if (rays->ray_left)
			vr->flag = -1;
		if (has_wall(nextverttouchx + vr->flag, nextverttouchy, vr))
		{
			rays->foundvertwallhit = 1;
			rays->vertwallhitx = nextverttouchx;
			rays->vertwallhity = nextverttouchy;
			break ;
		}
		else
		{
			nextverttouchx += rays->xstep;
			nextverttouchy += rays->ystep;
		}
	}
}

void	cast_vert(t_vars *vr, t_ray *rays, int ray)
{
	rays->foundvertwallhit = 0;
	rays->xintercept = floor(vr->x / TILESISE) * TILESISE;
	if (rays->ray_right)
		rays->xintercept += TILESISE;
	else
		rays->xintercept += 0;
	rays->yintercept = vr->y + (rays->xintercept - vr->x)
		* tan(rays->ray_angle);
	rays->xstep = TILESISE;
	if (rays->ray_left)
		rays->xstep *= -1;
	else
		rays->xstep *= 1;
	rays->ystep = TILESISE * tan(rays->ray_angle);
	if (rays->ray_up && rays->ystep > 0)
		rays->ystep *= -1;
	else
		rays->ystep *= 1;
	if (rays->ray_down && rays->ystep < 0)
		rays->ystep *= -1;
	else
		rays->ystep *= 1;
	vr->flag = 0;
	check_vert(vr, rays, ray);
}
