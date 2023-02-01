/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:40:25 by oouazahr          #+#    #+#             */
/*   Updated: 2023/02/01 20:26:14 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3er.h"

int	main(int ac, char **av)
{
	t_cube	*p;
	t_vars	*px;

	if (ac == 2)
	{
		p = parse(av);
		px = (t_vars *)malloc(sizeof(t_vars));
		if (!px)
			return (0);
		px->map = p;
		system("leaks cub3D");
		execution(px);
	}
	return (0);
}
