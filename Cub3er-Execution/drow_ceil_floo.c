/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_ceil_floo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:28:23 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 03:27:59 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	drow_ceil_floo(t_ray *rays, t_vars *vr, int ray)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rays->top_wall)
	{
		j = 0;
		my_mlx_pixel_put(&vr->data, ray, i, vr->map->c);
		i++;
	}
	i = rays->bottom_wall;
	while (i < 980)
	{
		my_mlx_pixel_put(&vr->data, ray, i, vr->map->f);
		i++;
	}
}
