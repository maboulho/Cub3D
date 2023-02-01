/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:32:15 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 19:02:15 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	p_player(t_vars *p)
{
	if (p->map->direction)
	{
		p->y = p->map->x * TILESISE + TILESISE / 2;
		p->x = p->map->y * TILESISE + TILESISE / 2;
	}
}

int	has_wall(double x, double y, t_vars *vr)
{
	if (ft_strlen2(vr->map->cube_map[(int)floor(y / TILESISE)])
		< (int)floor(x / TILESISE))
		return (1);
	if (vr->map->cube_map[(int)floor(y / TILESISE)][(int)floor(x / TILESISE)]
		== '1')
		return (1);
	return (0);
}

int	render_next_frame(void *ptr)
{
	t_vars	*vr;

	vr = (t_vars *)ptr;
	clear_win(vr);
	move_position(vr);
	cast_rays(vr, &vr->rays);
	rendering_map(vr);
	mlx_put_image_to_window(vr->mlx, vr->mlx_win, vr->data.img, 0, 0);
	return (0);
}

int	mouse_hook(int mouse)
{
	if (mouse == 0)
	{
		write(1, "You haven't finished the game\n", 31);
		exit (0);
	}
	return (0);
}

void	execution(t_vars *vr)
{
	init_var(vr);
	p_player(vr);
	get_player_angle(vr);
	vr->data.addr = mlx_get_data_addr(vr->data.img,
			&vr->data.bits_per_pixel,
			&vr->data.line_length,
			&vr->data.endian);
	get_image_addr(vr);
	mlx_hook(vr->mlx_win, 17, 0L, mouse_hook, (void *)0);
	mlx_hook(vr->mlx_win, 2, 0L, &press_key, vr);
	mlx_hook(vr->mlx_win, 3, 0L, &release_key, vr);
	mlx_hook(vr->mlx_win, 4, 0L, &button_press, vr);
	mlx_hook(vr->mlx_win, 5, 0L, &button_release, vr);
	mlx_hook(vr->mlx_win, 6, 0L, &button_mouse, vr);
	mlx_loop_hook(vr->mlx, render_next_frame, vr);
	mlx_loop(vr->mlx);
}
