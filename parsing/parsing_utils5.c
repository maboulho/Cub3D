/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:03:32 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 03:48:04 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_values2(t_cube *p)
{
	p->start = 0;
	p->end = 0;
	p->j = 0;
}

int	ft_strchr2(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{	
		if (str[i] == ((char)c))
		{
			return (i);
		}
			i++;
	}
	return (0);
}

int	longest_str(char **s)
{
	int	i;
	int	hold;

	i = 0;
	hold = ft_strlen2(s[0]);
	while (s[i])
	{
		if (hold < ft_strlen2(s[i]))
			hold = ft_strlen2(s[i]);
		i++;
	}
	return (hold);
}
