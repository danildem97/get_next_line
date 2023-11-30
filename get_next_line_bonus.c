/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:56:23 by ddemydov          #+#    #+#             */
/*   Updated: 2023/03/13 15:45:41 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free(char *save, char *line)
{
	char	*str;

	if (save == 0)
	{
		str = ft_strjoin("", line);
	}
	else
	{
		str = ft_strjoin(save, line);
		free(save);
	}
	return (str);
}

char	*ft_prep_static(char *str)
{
	size_t	i;
	char	*t;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{	
		free(str);
		return (NULL);
	}
	t = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	free(str);
	return (t);
}

char	*ft_get_answer(char *save)
{
	int		index;
	char	*answer;

	index = 0;
	while (save[index] && save[index] != '\n')
	{
		index++;
	}
	answer = ft_substr(save, 0, index + 1);
	return (answer);
}

char	*ft_read_line(int fd, char *save)
{
	char	*line;
	int		read_fd;

	line = malloc(BUFFER_SIZE + 1);
	read_fd = read(fd, line, BUFFER_SIZE);
	while (read_fd != 0)
	{
		if (read_fd == -1)
		{	
			if (save)
			{
				free(save);
			}
			free(line);
			return (0);
		}
		line[read_fd] = 0;
		save = ft_strjoin_free(save, line);
		if (ft_strrchr(line, '\n'))
			break ;
		read_fd = read(fd, line, BUFFER_SIZE);
	}
	free (line);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*answer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	if (read(fd, 0, 0) < 0)
	{
		if (save[fd])
			free(save[fd]);
		save[fd] = 0;
		return (0);
	}
	if (!ft_strrchr(save[fd], '\n'))
	{
		save[fd] = ft_read_line(fd, save[fd]);
	}
	if (!save[fd])
	{
		return (0);
	}
	answer = ft_get_answer(save[fd]);
	save[fd] = ft_prep_static(save[fd]);
	return (answer);
}
