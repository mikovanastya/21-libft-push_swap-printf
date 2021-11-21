/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:36:44 by rtwitch           #+#    #+#             */
/*   Updated: 2021/11/20 17:50:40 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(int fd, char *str)
{
	char	*buff;
	char	*tmp;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	str = get_null(str);
	rd_bytes = 1;
	while (!(ft_strchr(str, '\n')) && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	free(buff);
	return (str);
}

char	*get_null(char *str)
{
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		if (!str)
			return (0);
	}
	return (str);
}

char	*get_first_line(char *line)
{
	char		*word;
	int			i;
	int			j;

	i = 0;
	if (line[i] == '\0')
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	j = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
		word[j++] = line[i++];
	if (line[i] == '\n')
		word[j++] = line[i++];
	word[j] = '\0';
	return (word);
}

char	*get_last_line(char *line)
{
	int		i;
	int		j;
	char	*word;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (0);
	}
	word = malloc(sizeof(char) * ((ft_strlen(line) - i) + 1));
	if (!word)
		return (0);
	j = 0;
	while (line[i] != '\0')
		word[j++] = line[++i];
	word[j] = '\0';
	free(line);
	return (word);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stat = make_line(fd, stat);
	if (!stat)
		return (NULL);
	line = get_first_line(stat);
	stat = get_last_line(stat);
	return (line);
}
