/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:33:51 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 03:39:00 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	put_player(t_vars *vr, t_mini *mini)
{
	mini->i = 0;
	while (mini->i < 10)
	{
		mini->j = 0;
		while (mini->j < 10)
		{
			my_mlx_pixel_put(&vr->data, (vr->x * 0.2) + mini->j - 5, (vr->y
					* 0.2) - 5 + mini->i, 0x6699CC);
			mini->j++;
		}
		mini->i++;
	}
}

void	put_floor(t_vars *vr, t_mini *mini)
{
	mini->i = 0;
	while (vr->map->cube_map[mini->i])
	{
		mini->j = 0;
		while (vr->map->cube_map[mini->i][mini->j])
		{
			if (vr->map->cube_map[mini->i][mini->j] == '0'
				|| vr->map->cube_map[mini->i][mini->j] == vr->map->direction)
				put_mini_floor(vr, mini);
			mini->j++;
		}
		mini->i++;
	}
}

void	put_wall(t_vars *vr, t_mini *mini)
{
	mini->i = 0;
	while (vr->map->cube_map[mini->i])
	{
		mini->j = 0;
		while (vr->map->cube_map[mini->i][mini->j])
		{
			if (vr->map->cube_map[mini->i][mini->j] == '1')
				put_mini_wall(vr, mini);
			mini->j++;
		}
		mini->i++;
	}
}

void	rendering_map(t_vars *vr)
{
	t_mini	mini;

	put_wall(vr, &mini);
	put_floor(vr, &mini);
	put_player(vr, &mini);
}
