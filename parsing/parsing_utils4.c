/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:42:17 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 02:33:04 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_map_values(t_cube *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < p->index)
	{
		check_map_values2(p, i, j);
		i++;
		j = 0;
	}
	if (p->c == 1 && p->f == 1 && p->s == 1
		&& p->e == 1 && p->w == 1 && p->n == 1)
		init_map_values(p);
	else
	{
		printf("textures not valid\n");
		exit(0);
	}
}

void	check_map_values2(t_cube *p, int i, int j)
{
	while (p->map[i][j] == ' ' || p->map[i][j] == '\t')
			j++;
	if (p->map[i][j] == 'S' && p->map[i][j + 1] == 'O'
		&& (p->map[i][j + 2] == ' ' || p->map[i][j + 2] == '\t'))
		p->s++;
	else if (p->map[i][j] == 'E' && p->map[i][j + 1] == 'A'
		&& (p->map[i][j + 2] == ' ' || p->map[i][j + 2] == '\t'))
		p->e++;
	else if (p->map[i][j] == 'W' && p->map[i][j + 1] == 'E'
		&& (p->map[i][j + 2] == ' ' || p->map[i][j + 2] == '\t'))
		p->w++;
	else if (p->map[i][j] == 'N' && p->map[i][j + 1] == 'O'
		&& (p->map[i][j + 2] == ' ' || p->map[i][j + 2] == '\t'))
		p->n++;
	else if (p->map[i][j] == 'F' && (p->map[i][j + 1] == ' '
		|| p->map[i][j + 1] == '\t'))
		p->f++;
	else if (p->map[i][j] == 'C' && (p->map[i][j + 1] == ' '
		|| p->map[i][j + 1] == '\t'))
		p->c++;
}

void	cub_to_2d(t_cube *p, char *s)
{
	int	fd;
	int	i;

	init_values(p);
	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		printf("file not found\n");
		exit(1);
	}
	p->lenght = lenght(fd, s);
	p->map = malloc(sizeof(char *) * (p->lenght + 1));
	if (!p->map)
		return ;
	while (p->lenght > i)
	{
		p->map[i] = get_next_line(fd);
		i++;
	}
	p->map[i] = NULL;
	if (p->map)
		check_befor_map(p);
}

void	init_map_values(t_cube *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < p->index)
	{
		init_map_values2(p, i, j);
		i++;
		j = 0;
	}
	check_rgb(p);
}

void	init_map_values2(t_cube *p, int i, int j)
{
	while (p->map[i][j] == ' ' || p->map[i][j] == '\t')
		j++;
	if (p->map[i][j] == 'S' && p->map[i][j + 1] == 'O'
		&& p->map[i][j + 2] == ' ')
		create_so(p, i);
	else if (p->map[i][j] == 'E' && p->map[i][j + 1] == 'A'
		&& p->map[i][j + 2] == ' ')
		create_ea(p, i);
	else if (p->map[i][j] == 'W' && p->map[i][j + 1] == 'E'
		&& p->map[i][j + 2] == ' ')
		create_we(p, i);
	else if (p->map[i][j] == 'N' && p->map[i][j + 1] == 'O'
		&& p->map[i][j + 2] == ' ')
		create_no(p, i);
	else if (p->map[i][j] == 'F' && p->map[i][j + 1] == ' ')
		create_f(p, i);
	else if (p->map[i][j] == 'C' && p->map[i][j + 1] == ' ')
		create_c(p, i);
}
