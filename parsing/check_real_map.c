/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_real_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:55:52 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/02 01:56:43 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error_blank(void)
{
	printf("error blank\n");
	exit(1);
}

void	check_player(char **s, int i, int j)
{
	if (s[i][j - 1] != '1' && s[i][j - 1] != '0')
		error_blank();
	if (s[i][j + 1] != '1' && s[i][j + 1] != '0')
		error_blank();
	if (s[i - 1][j] != '1' && s[i - 1][j] != '0')
		error_blank();
	if (s[i + 1][j] != '1' && s[i + 1][j] != '0')
		error_blank();
}

void	check_zero2(char **s, int i, int j)
{
	if (s[i][j - 1] != '1' && s[i][j - 1] != '0' && s[i][j - 1] != 'S'
		&& s[i][j - 1] != 'N' && s[i][j - 1] != 'E' && s[i][j - 1] != 'W')
		error_blank();
	else if (s[i][j + 1] != '1' && s[i][j + 1] != '0' && s[i][j + 1] != 'S'
		&& s[i][j + 1] != 'N' && s[i][j + 1] != 'E' && s[i][j + 1] != 'W')
		error_blank();
	else if (s[i - 1][j] != '1' && s[i - 1][j] != '0' && s[i - 1][j] != 'S'
		&& s[i - 1][j] != 'N' && s[i - 1][j] != 'E' && s[i - 1][j] != 'W')
		error_blank();
	else if (s[i + 1][j] != '1' && s[i + 1][j] != '0' && s[i + 1][j] != 'S'
		&& s[i + 1][j] != 'N' && s[i + 1][j] != 'E' && s[i + 1][j] != 'W')
		error_blank();
	return ;
}

int	check_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ' && s[i] != '0' && s[i] != 'N'
			&& s[i] != 'S' && s[i] != 'W' && s[i] != 'E' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_duplicates(char **s)
{
	int	i;
	int	flag;
	int	j;

	i = 0;
	flag = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'S' || s[i][j] == 'N'
				|| s[i][j] == 'E' || s[i][j] == 'W')
				flag++;
			j++;
		}
		i++;
	}
	flagino(flag);
}
