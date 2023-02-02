/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:56:54 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/02 03:52:21 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cube.h"

void	check_file_name(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 1] == 'b' && s[i - 2] == 'u'
		&& s[i - 3] == 'c' && s[i - 4] == '.')
		return ;
	else
	{
		printf("ERROR : invalid file\n");
		exit(0);
	}
}

t_cube	*parse(char **av)
{
	t_cube	*p;

	p = malloc(sizeof(t_cube));
	check_file_name(av[1]);
	cub_to_2d(p, av[1]);
	return (p);
}

void	check_xpm(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (!(s[i - 1] == 'm' && s[i - 2] == 'p'
			&& s[i - 3] == 'x' && s[i - 4] == '.'))
	{
		printf("check texture xpm\n");
		exit (1);
	}
	else
		open_xpm(s);
}

void	open_xpm(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		printf("cant open xpm\n");
		exit (1);
	}
	else
		return ;
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
