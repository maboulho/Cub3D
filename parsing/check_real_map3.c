/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_real_map3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:53:44 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/02 04:08:46 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_real_map2(t_cube *p, int i, int j, int ind)
{
	while (j < p->lenght)
	{
		if (p->map[j][0] == '0')
			error_blank();
		if (p->map[j][0] == '\n')
		{
			p->cube_map1[i][0] = '\n';
			ind++;
		}
		while (p->cube_map1[i][0] != '\n' && p->map[j][ind] != '\n'
			&& p->map[j][ind] != '\0')
		{
			p->cube_map1[i][ind] = p->map[j][ind];
			ind++;
		}
		p->cube_map1[i][ind] = '\0';
		ind = 0;
		i++;
		j++;
	}
}

void	new_map2(t_cube *p, int lenght, int i, int j)
{
	int	big;

	big = get_width(p->cube_map1);
	while (i < lenght)
	{
		j = 0;
		while (j < big)
		{
			if (j < ft_strlen(p->cube_map1[i]))
				p->cube_map[i][j] = p->cube_map1[i][j];
			else
				p->cube_map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

int	check_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
