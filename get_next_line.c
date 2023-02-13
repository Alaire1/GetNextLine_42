/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:48:43 by akaraban          #+#    #+#             */
/*   Updated: 2023/02/13 01:37:28 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*prepare_new_line(int fd, char *temp)
{
	char	*buffer;
	int		readed;

	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
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
		buffer[readed] = '\0';
		temp = ft_strjoining(temp, buffer);	
	}
	free(buffer);
	return (temp);
}

char	*fixed_line(char *temp)
{
	size_t		i;
	char	*line;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_nextline(char *temp)
{
	int		i;
	int		j;
	char	*tab;
	size_t size;

	size = ft_strlen(temp);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	tab = malloc(sizeof(char) * (size - i + 1));
	if (!tab)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		tab[j++] = temp[i++];
	tab[j] = '\0';
	free(temp);
	return (tab);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	temp = prepare_new_line(fd, temp);
	if (!temp)
		return (NULL);
	next_line = fixed_line(temp);
	temp = get_nextline(temp);
	return (next_line);
}