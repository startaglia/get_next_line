/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:27:02 by startagl          #+#    #+#             */
/*   Updated: 2023/01/27 11:51:19 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_first_str(int fd, char *str)
{
	char	*str_buf;
	ssize_t	fd_read;

	str_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_buf)
		return (NULL);
	fd_read = 1;
	while (!(ft_strchr(str, '\n')) && fd_read > 0)
	{
		fd_read = read(fd, str_buf, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(str_buf);
			return (NULL);
		}
		str_buf[fd_read] = '\0';
		str = ft_strjoin(str, str_buf);
	}
	free(str_buf);
	return (str);
}

char	*clean_str(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	result = (char *)malloc(i + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*new_line(char *str)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!string)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		string[j++] = str[i++];
	string[j] = '\0';
	free(str);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = get_first_str(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	next_line = clean_str(line[fd]);
	line[fd] = new_line(line[fd]);
	return (next_line);
}
