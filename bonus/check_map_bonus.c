/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:29:22 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/22 19:09:50 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_pos_c(t_sl *sl, int i, int j)
{
	int		x;
	t_pos	*tmp;

	x = 0;
	tmp = (t_pos *)malloc(sizeof(t_pos) * (sl->col + 2));
	if (tmp == NULL)
		return (sl->error = BASIC_ERROR);
	while (x < sl->col)
	{
		tmp[x] = sl->c[x];
		x++;
	}
	tmp[x].y = j;
	tmp[x].x = i;
	free(sl->c);
	sl->c = tmp;
	sl->col++;
	return (SUCCESS);
}

static int	get_pos_e(t_sl *sl, int i, int j)
{
	int		x;
	t_pos	*tmp;

	x = 0;
	tmp = (t_pos *)malloc(sizeof(t_pos) * (sl->exit + 2));
	if (tmp == NULL)
		return (sl->error = BASIC_ERROR);
	while (x < sl->exit)
	{
		tmp[x] = sl->e[x];
		x++;
	}
	tmp[x].y = j;
	tmp[x].x = i;
	free(sl->e);
	sl->e = tmp;
	sl->exit++;
	return (SUCCESS);
}

static int	get_pos(t_sl *sl, int i, int j)
{
	int	ret;

	if (sl->map[j][i] == 'C')
	{
		ret = get_pos_c(sl, i, j);
		if (ret != SUCCESS)
			return (sl->error);
	}
	if (sl->map[j][i] == 'E')
	{
		ret = get_pos_e(sl, i, j);
		if (ret != SUCCESS)
			return (sl->error);
	}
	return (SUCCESS);
}

static int	check_c(t_sl *sl, int i, int j)
{
	int	ret;

	if (!(ft_strchr("01CEP", sl->map[j][i])))
		return (sl->error = NOT_VALID_M_ERROR);
	if (ft_strchr("0CEP", sl->map[j][i]))
		if (i == 0 || j == 0 || i == (int)ft_strlen(sl->map[j]) - 1
			|| j == sl->m - 1)
			return (sl->error = NOT_VALID_M_ERROR);
	if (sl->map[j][i] == 'P')
	{
		sl->p.x = i;
		sl->p.y = j;
		sl->player++;
	}
	if (sl->map[j][i] == 'C' || sl->map[j][i] == 'E')
	{
		ret = get_pos(sl, i, j);
		if (ret != SUCCESS)
			return (sl->error);
	}
	return (SUCCESS);
}

int	check_map(t_sl *sl)
{
	int	i;
	int	j;
	int	ret;

	j = 0;
	while (sl->map[j])
	{
		if (j > 0 && (ft_strlen(sl->map[j]) != ft_strlen(sl->map[j - 1])))
			return (sl->error = NOT_RECT_ERROR);
		i = 0;
		while (sl->map[j][i])
		{
			ret = check_c(sl, i, j);
			if (ret != SUCCESS)
				return (sl->error);
			i++;
		}
		j++;
		sl->dim.y++;
	}
	if (sl->player != 1 || sl->col < 1 || sl->exit < 1)
		return (sl->error = NB_CEP_ERROR);
	return (SUCCESS);
}
