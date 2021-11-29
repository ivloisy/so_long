/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:34:18 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/28 17:08:00 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	arg_check(int ac, char **av)
{
	if (ac != 2)
		return (NB_ARG_ERROR);
	else
	{
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
			return (FILE_TYPE_ERROR);
	}
	return (SUCCESS);
}

static int	add_line(char *line, t_sl *sl)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (sl->m + 2));
	if (tmp == NULL)
		return (BASIC_ERROR);
	while (sl->map[++i])
		tmp[i] = sl->map[i];
	tmp[i] = ft_strdup(line);
	tmp[i + 1] = NULL;
	free(sl->map);
	sl->map = tmp;
	i = -1;
	while (tmp[++i])
		sl->map[i] = tmp[i];
	sl->map[i] = NULL;
	sl->m++;
	return (SUCCESS);
}

static int	get_info(int fd, t_sl *sl)
{
	int		ret;
	char	*line;

	ret = 1;
	sl->map = (char **)malloc(sizeof(char *));
	if (sl->map == NULL)
		return (BASIC_ERROR);
	sl->map[0] = NULL;
	while (ret > 0 && sl->error == SUCCESS)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			break ;
		sl->error = add_line(line, sl);
		if (ret <= 0 || sl->error != SUCCESS)
			break ;
		free(line);
	}
	free(line);
	line = NULL;
	if (ret == -1)
		return (READ_ERROR);
	if (sl->error != SUCCESS)
		return (sl->error);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_sl	sl;
	int		fd;

	ft_bzero(&sl, sizeof(sl));
	sl.error = arg_check(ac, av);
	if (sl.error != SUCCESS)
		exit_error(&sl);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		sl.error = BASIC_ERROR;
		exit_error(&sl);
	}
	sl.error = get_info(fd, &sl);
	if (sl.error != SUCCESS)
		exit_error(&sl);
	close(fd);
	sl.error = check_map(&sl);
	if (sl.error != SUCCESS)
		exit_error(&sl);
	sl.error = launch(&sl);
	if (sl.error != SUCCESS)
		exit_error(&sl);
	return (EXIT_SUCCESS);
}
