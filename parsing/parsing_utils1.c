/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 05:59:37 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 01:52:19 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cube.h"

int	get_hight(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_width(char **s)
{
	int	lenght;
	int	i;

	i = 0;
	lenght = 0;
	while (s[i])
	{
		if ((int)lenght < ft_strlen(s[i]))
			lenght = ft_strlen(s[i]);
		i++;
	}
	return (lenght);
}

void	check_comma_plus2(char *s, int *i)
{
	if (s[0] == ',')
		rgb_error();
	if (s[0] == '+')
	{
		if (ft_isdigit(s[1]) == 0)
			rgb_error();
	}
	(*i)++;
}

void	check_comma_plus(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	check_comma_plus2(s, &i);
	while (s[i])
	{
		if (s[i] == ',')
		{
			if (ft_isdigit(s[i - 1]) && (s[i + 1] == '+'
					|| ft_isdigit(s[i + 1])))
				comma++;
			else
				rgb_error();
		}
		else if (s[i] == '+')
		{
			if (s[i - 1] != ',' || !ft_isdigit(s[i + 1]))
				rgb_error();
		}
		i++;
	}
	if (comma != 2)
		rgb_error();
}

void	check_rgb(t_cube *p)
{
	check_f_rgb(p);
	check_c_rgb(p);
	check_real_map(p);
}
