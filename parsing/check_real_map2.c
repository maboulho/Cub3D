/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:14:54 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 01:25:22 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_map_error(t_cube *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->cube_map[i])
	{
		j = 0;
		while (p->cube_map[i][j])
		{
			if (!check_chars(p->cube_map[i]))
			{
				printf("invalid map characters\n");
				exit (0);
			}
			j++;
		}
		i++;
	}
	check_duplicates(p->cube_map);
	check_zero(p->cube_map, p);
}

void	check_real_map(t_cube *p)
{
	int	i;
	int	j;

	i = 0;
	j = p->index;
	p->cube_map = malloc(sizeof(char *) * p->lenght + 1);
	if (!p->cube_map)
		return ;
	i = 0;
	while (j < p->lenght)
	{
		p->cube_map[i] = p->map[j];
		i++;
		j++;
	}
	p->cube_map[i] = NULL;
	check_map_error(p);
}

void	check_zero(char **s, t_cube *p)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '0')
				check_zero2(s, i, j);
			else if (s[i][j] == 'N' || s[i][j] == 'E'
				|| s[i][j] == 'W' || s[i][j] == 'S')
			{
				p->direction = s[i][j];
				p->x = i;
				p->y = j;
				check_player(s, i, j);
			}
			j++;
		}
		i++;
	}
}

void	flagino(int flag)
{
	if (flag > 1)
	{
		printf("Oops more than one player\n");
		exit (0);
	}
	else if (flag == 0)
	{
		printf("Oops there is no player\n");
		exit (0);
	}
}
