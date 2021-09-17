/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 02:52:35 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/13 04:41:50 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	len_line(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

static int	read_buf(int fd, char **str)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tmp = ft_strjoin((*str), buf);
		if (tmp == NULL)
		{
			free(tmp);
			tmp = NULL;
			ret = -1;
		}
		free((*str));
		(*str) = tmp;
		if (ret < 1)
			break ;
		if (ft_strchr((*str), '\n'))
			break ;
	}
	return (ret);
}

static void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[_SC_OPEN_MAX];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(ft_strchr(str[fd], '\n')))
	{
		ret = read_buf(fd, &str[fd]);
		if (ret == -1)
			return (-1);
	}
	if (str[fd])
		(*line) = ft_substr(str[fd], 0, len_line(str[fd]));
	else
		(*line) = ft_strdup("");
	if (ft_strchr(str[fd], '\n'))
	{
		tmp = ft_strdup(&str[fd][len_line(str[fd]) + 1]);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	ft_free(str[fd]);
	return (0);
}
