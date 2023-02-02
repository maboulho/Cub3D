/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:00:18 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/02 03:53:19 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_f(t_cube *p, int i)
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
	p->fc = ft_substr1(p->map[i], p->start, p->end - p->start);
}

void	creat_f_part(t_cube *p)
{
	p->f_rgb = ft_split(p->fc, ',');
	p->tab_f[0] = ft_atoi(p->f_rgb[0]);
	p->tab_f[1] = ft_atoi(p->f_rgb[1]);
	p->tab_f[2] = ft_atoi(p->f_rgb[2]);
	if (p->tab_f[0] < 256 && p->tab_f[1] < 256 && p->tab_f[2] < 256)
		p->f_final = (0 << 24 | p->tab_f[0] << 16
				| p->tab_f[1] << 8 | p->tab_f[2]);
	else
		rgb_error();
}

void	check_f_rgb(t_cube *p)
{
	int	i;

	i = 0;
	while (p->fc[i])
	{
		if (p->fc[i] != ',' && p->fc[i] != '+'
			&& !ft_isdigit(p->fc[i]))
			rgb_error();
		i++;
	}
	check_comma_plus(p->fc);
	creat_f_part(p);
}

void	check_zero(char **s, t_cube *p)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if ((s[i + 1] && (s[i + 1][0] == '\n'
			|| check_space_last(s[i + 1]))) || !s[i + 1])
			check_last_line(s[i]);
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == '0')
				check_zero2(s, i, j);
			if (s[i][j] == 'N' || s[i][j] == 'E'
				|| s[i][j] == 'W' || s[i][j] == 'S')
			{
				p->direction = s[i][j];
				p->x = i;
				p->y = j;
				check_player(s, i, j);
			}
		}
		i++;
	}
}
