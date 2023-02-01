/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 04:09:46 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 03:37:47 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	put_mini_floor(t_vars *vr, t_mini *mini)
{
	int	minimap;

	minimap = 0x0000FF;
	mini->a = 0;
	while (mini->a < TILESISE * 0.2)
	{
		mini->b = 0;
		while (mini->b < TILESISE * 0.2)
		{
			my_mlx_pixel_put(&vr->data, (mini->b + (mini->j
						* TILESISE * 0.2)), (mini->a + (mini->i
						* TILESISE * 0.2)),
				minimap);
			mini->b++;
		}
		mini->a++;
	}
}

void	put_mini_wall(t_vars *vr, t_mini *mini)
{
	int	minimap;

	minimap = 0x6699CC;
	mini->a = 0;
	while (mini->a < TILESISE * 0.2)
	{
		mini->b = 0;
		while (mini->b < TILESISE * 0.2)
		{
			my_mlx_pixel_put(&vr->data, (mini->b + (mini->j
						* TILESISE * 0.2)), (mini->a + (mini->i
						* TILESISE * 0.2)),
				minimap);
			mini->b++;
		}
		mini->a++;
	}
}
