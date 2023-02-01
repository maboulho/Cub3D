/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:44:03 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 18:40:52 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while ((int)i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = (char *)s1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)start)
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr1(char *s, int start, int len)
{
	int		i;
	char	*substr;

	substr = NULL;
	if (!s)
		return (NULL);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
