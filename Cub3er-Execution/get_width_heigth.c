/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_heigth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:37:09 by atouati           #+#    #+#             */
/*   Updated: 2023/01/15 05:00:18 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3er.h"

int	get_the_width(char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (len < ft_strlen2(str[i]))
			len = ft_strlen2(str[i]);
		i++;
	}
	return (len);
}

int	get_the_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
