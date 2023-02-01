/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:38:45 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 03:26:32 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	init_var(t_vars *vr)
{
	vr->num_col = get_the_width(vr->map->cube_map);
	vr->num_row = get_the_height(vr->map->cube_map);
	vr->num_ray = 1820;
	vr->turn_direction = 0;
	vr->move_direction = 0;
	vr->turn_mouse = 0;
	vr->left_rigth_direction = 0;
	vr->move_speed = 6;
	vr->turn_speed = 2.4 * M_PI / 180;
	vr->step = 0;
	vr->mlx = mlx_init();
	vr->mlx_win = mlx_new_window(vr->mlx, 1820, 980, "cub3d");
	vr->data.img = mlx_new_image(vr->mlx, 1820, 980);
}

void	init(t_ray *rays, int ray)
{
	(void)ray;
	rays->ray_angle = norm_angle(rays->ray_angle);
	rays->wall_hit_x = 0;
	rays->wall_hit_y = 0;
	rays->distance = 0;
	if (rays->ray_angle > 0 && rays->ray_angle < M_PI)
		rays->ray_down = 1;
	else
		rays->ray_down = 0;
	if (rays->ray_down)
		rays->ray_up = 0;
	else
		rays->ray_up = 1;
	if (rays->ray_angle < 0.5 * M_PI || rays->ray_angle > 1.5 * M_PI)
		rays->ray_right = 1;
	else
		rays->ray_right = 0;
	if (rays->ray_right)
		rays->ray_left = 0;
	else
		rays->ray_left = 1;
}
