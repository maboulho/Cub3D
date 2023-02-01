/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:32:34 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 18:38:02 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	norm_direction(t_vars *vr)
{
	vr->angle += vr->turn_direction * vr->turn_speed;
	vr->step = vr->move_direction * vr->move_speed;
	vr->step_r_l = (M_PI / 2) * vr->left_rigth_direction;
	if (vr->angle > 2 * M_PI)
		vr->angle -= 2 * M_PI;
	else if (vr->angle < 0)
		vr->angle += 2 * M_PI;
}

void	move(t_vars *vr, int x, int y)
{
	if (vr->map->cube_map[x][y] != '1')
	{
		if (vr->move_direction
			&& (ft_strchr2(" 0NSWE", vr->map->cube_map[(int)(x)][(int)vr->x
				/ TILESISE])))
			vr->y = vr->y + (sin(vr->angle) * vr->step);
		if (vr->move_direction
			&& (ft_strchr2(" 0NSWE", vr->map->cube_map[(int)vr->y
						/ TILESISE][(int)(y)])))
			vr->x = vr->x + (cos(vr->angle) * vr->step);
		x = (int)floor((vr->y + sin(vr->angle) * vr->step + (sin(vr->angle
							+ vr->step_r_l) * vr->move_speed)) / TILESISE);
		y = (int)floor((vr->x + cos(vr->angle) * vr->step + (cos(vr->angle
							+ vr->step_r_l) * vr->move_speed)) / TILESISE);
		if (vr->left_rigth_direction && vr->map->cube_map[x][y] != '1')
		{
			vr->x = vr->x + (cos(vr->angle + vr->step_r_l) * vr->move_speed);
			vr->y = vr->y + (sin(vr->angle + vr->step_r_l) * vr->move_speed);
		}
	}
}

void	move_position(t_vars *vr)
{
	int	x;
	int	y;
	int	l;
	int	k;

	norm_direction(vr);
	l = longest_str(vr->map->cube_map);
	k = ft_len(vr->map->cube_map);
	x = (int)floor((vr->y + sin(vr->angle) * vr->step) / TILESISE);
	y = (int)floor((vr->x + cos(vr->angle) * vr->step) / TILESISE);
	if ((y >= 0 && y < l) && (x >= 0 && x < k))
		move(vr, x, y);
	else
	{
		printf("END OF MAP\n");
		exit(0);
	}
}
