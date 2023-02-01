/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:00:50 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 02:40:24 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_c(t_cube *p, int i)
{
	init_values2(p);
	while (p->map[i][p->j])
	{
		while (p->map[i][p->j] == ' ' || p->map[i][p->j] == '\t')
			p->j++;
		while (p->map[i][p->j] != ' ' && p->map[i][p->j] != '\t')
			p->j++;
		while (p->map[i][p->j] == ' ' || p->map[i][p->j] == '\t')
			p->j++;
		p->start = p->j;
		while (p->map[i][p->j] != '\n')
		{
			if ((p->map[i][p->j] == ' ' || p->map[i][p->j] == '\t')
				&& check_only_spaces(p->map[i], p->j))
				break ;
			p->j++;
		}
		p->end = p->j;
		break ;
		p->j++;
	}
	p->cc = ft_substr1(p->map[i], p->start, p->end - p->start);
}

void	creat_c_part(t_cube *p)
{
	p->c_rgb = ft_split(p->cc, ',');
	p->tab_c[0] = ft_atoi(p->c_rgb[0]);
	p->tab_c[1] = ft_atoi(p->c_rgb[1]);
	p->tab_c[2] = ft_atoi(p->c_rgb[2]);
	if (p->tab_c[0] < 256 && p->tab_c[1] < 256 && p->tab_c[2] < 256)
		p->c_final = (0 << 24 | p->tab_c[0] << 16
				| p->tab_c[1] << 8 | p->tab_c[2]);
	else
		rgb_error();
}

void	check_c_rgb(t_cube *p)
{
	int	i;

	i = 0;
	while (p->cc[i])
	{
		if (p->cc[i] != ',' && p->cc[i] != '+' && !ft_isdigit(p->cc[i]))
			rgb_error();
		i++;
	}
	check_comma_plus(p->cc);
	creat_c_part(p);
}
