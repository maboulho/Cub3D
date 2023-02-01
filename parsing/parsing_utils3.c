/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:02:01 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 03:15:16 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	if (ft_strlen(str) > 4)
		rgb_error();
	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	rgb_error(void)
{
	printf("error rgb\n");
	exit(0);
}

void	error_textures(void)
{
	printf("error in textures\n");
	exit(0);
}
