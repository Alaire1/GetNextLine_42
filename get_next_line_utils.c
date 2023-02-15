/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:05:46 by akaraban          #+#    #+#             */
/*   Updated: 2023/02/16 00:33:25 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoining(char *str, char *buff)
{
	char	*result;
	int		i;
	int		x;

	i = -1;
	x = 0;
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	result = malloc(ft_strlen(str) + ft_strlen(buff) + 1);
	if (!str || !buff || !result)
		return (0);
	while (str[++i])
		result[i] = str[i];
	while (buff[x])
	{
		result[i] = buff[x];
		i++;
		x++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
