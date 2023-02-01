/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hieght.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:31:32 by atouati           #+#    #+#             */
/*   Updated: 2023/01/15 05:18:40 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	wall_hieght(t_vars *vr, t_ray *rays, int ray)
{
	double	distance_plane;

	(void)ray;
	distance_plane = (1820 / 2) / tan((60 * M_PI / 180) / 2);
	rays->wall_hieght = (TILESISE / (rays->distance
				* cos(rays->ray_angle - vr->angle))) * distance_plane;
	rays->top_wall = ((980 / 2) - rays->wall_hieght / 2);
	if (rays->top_wall < 0)
		rays->top_wall = 0;
	rays->bottom_wall = ((980 / 2) + rays->wall_hieght / 2);
	if (rays->bottom_wall > 980)
		rays->bottom_wall = 980;
}
