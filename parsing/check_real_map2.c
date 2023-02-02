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
	int	ind;

	ind = 0;
	i = 0;
	j = p->index;
	p->cube_map1 = malloc(sizeof(char *) * p->lenght + 1);
	if (!p->cube_map1)
		return ;
	while (j < p->lenght)
	{
		p->cube_map1[i] = malloc(sizeof(char) * (ft_strlen(p->map[j]) + 1));
		i++;
		j++;
	}
	p->cube_map1[i] = NULL;
	j = p->index;
	i = 0;
	check_real_map2(p, i, j, ind);
	new_map(p);
	check_map_error(p);
}

void	new_map(t_cube *p)
{
	int	i;
	int	j;
	int	lenght;
	int	big;

	lenght = p->lenght - p->index;
	big = get_width(p->cube_map1);
	j = 0;
	i = 0;
	p->cube_map = malloc(sizeof(char *) * (lenght + 1));
	if (!p->cube_map)
		return ;
	p->cube_map[lenght] = NULL;
	while (i < lenght)
	{
		p->cube_map[i] = malloc(sizeof(char) * (big + 1));
		p->cube_map[i][big] = '\0';
		i++;
	}
	i = 0;
	new_map2(p, lenght, i, j);
	if (p->cube_map[0][big - 1] == ' ')
		p->cube_map[0][big - 1] = '1';
	if (p->cube_map[lenght - 1][big - 1] == ' ')
		p->cube_map[lenght - 1][big - 1] = '1';
}

void	check_last_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
		{
			printf("error in map\n");
			exit(0);
		}
		i++;
	}
}

int	check_space_last(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
