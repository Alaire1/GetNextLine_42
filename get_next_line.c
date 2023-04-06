/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:48:43 by akaraban          #+#    #+#             */
/*   Updated: 2023/02/19 19:32:27 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*prepare_new_line(int fd, char *temp, char *buffer)
{
	int		readed;

	readed = 1;
	while (readed > 0 && !ft_strchr(temp, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		else if (readed == 0)
			break ;
		buffer[readed] = '\0';
		temp = ft_strjoining(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*fixed_line(char *temp)
{
	size_t		i;
	char		*current_line;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	current_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!current_line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		current_line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		current_line[i] = temp[i];
		i++;
	}
	current_line[i] = '\0';
	return (current_line);
}

char	*get_nextline(char *temp)
{
	int		i;
	int		x;
	char	*str;
	size_t	size;

	size = ft_strlen(temp);
	i = 0;
	x = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = malloc(sizeof(char) * (size - i + 1));
	if (!str)
		return (NULL);
	while (temp[++i])
		str[x++] = temp[i];
	str[x] = '\0';
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*temp;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp = prepare_new_line(fd, temp, buffer);
	if (!temp)
		return (NULL);
	next_line = fixed_line(temp);
	temp = get_nextline(temp);
	return (next_line);
}
