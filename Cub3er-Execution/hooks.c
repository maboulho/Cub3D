/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:46:07 by atouati           #+#    #+#             */
/*   Updated: 2023/01/15 05:01:59 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

int	press_key(int keycode, void *ptr)
{
	t_vars	*vr;

	vr = (t_vars *)ptr;
	if (keycode == 123)
		vr->turn_direction = -1;
	if (keycode == 124)
		vr->turn_direction = 1;
	if (keycode == 13)
		vr->move_direction = 1;
	if (keycode == 1)
		vr->move_direction = -1;
	if (keycode == 0)
		vr->left_rigth_direction = -1;
	if (keycode == 2)
		vr->left_rigth_direction = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	release_key(int keycode, void *ptr)
{
	t_vars	*vr;

	vr = (t_vars *)ptr;
	if (keycode == 123)
		vr->turn_direction = 0;
	if (keycode == 124)
		vr->turn_direction = 0;
	if (keycode == 13)
		vr->move_direction = 0;
	if (keycode == 1)
		vr->move_direction = 0;
	if (keycode == 0)
		vr->left_rigth_direction = 0;
	if (keycode == 2)
		vr->left_rigth_direction = 0;
	return (0);
}

int	button_release(int button, int x, int y, void *ptr)
{
	t_vars	*vr;

	(void)x;
	(void)y;
	vr = (t_vars *)ptr;
	if (button == 1)
	{
		vr->turn_mouse = 0;
	}
	return (0);
}

int	button_mouse(int x, int y, void *ptr)
{
	t_vars	*vr;

	(void)y;
	vr = (t_vars *)ptr;
	if (vr->turn_mouse == 1)
	{
		if (vr->move_x > x)
			vr->angle += 0.03;
		if (vr->move_x < x)
			vr->angle -= 0.03;
	}
	return (0);
}

int	button_press(int button, int x, int y, void *ptr)
{
	t_vars	*vr;

	(void)y;
	vr = (t_vars *)ptr;
	if (button == 1)
	{
		vr->move_x = x;
		vr->turn_mouse = 1;
	}
	return (0);
}
