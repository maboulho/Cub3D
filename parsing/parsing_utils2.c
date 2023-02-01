/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:37:20 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 20:27:04 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cube.h"

int	check_only_spaces(char *s, int i)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	create_so(t_cube *p, int i)
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
	p->so = ft_substr1(p->map[i], p->start, p->end - p->start);
	check_xpm(p->so);
}

void	create_ea(t_cube *p, int i)
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
	p->ea = ft_substr1(p->map[i], p->start, p->end - p->start);
	check_xpm(p->ea);
}

void	create_no(t_cube *p, int i)
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
	p->no = ft_substr1(p->map[i], p->start, p->end - p->start);
	check_xpm(p->no);
}

void	create_we(t_cube *p, int i)
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
	p->we = ft_substr1(p->map[i], p->start, p->end - p->start);
	check_xpm(p->we);
}
