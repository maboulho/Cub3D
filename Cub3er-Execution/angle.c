/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:41:32 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 19:01:45 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

void	get_player_angle(t_vars *vr)
{
	if (vr->map->direction == 'S')
		vr->angle = M_PI / 2;
	else if (vr->map->direction == 'N')
		vr->angle = (3 * M_PI) / 2;
	else if (vr->map->direction == 'W')
		vr->angle = M_PI;
	else if (vr->map->direction == 'E')
		vr->angle = 0;
	return ;
}

double	norm_angle(double ray_angle)
{
	ray_angle = remainder(ray_angle, 2 * M_PI);
	if (ray_angle < 0)
		return (ray_angle + 2 * M_PI);
	return (ray_angle);
}

int	ft_strlen2(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
