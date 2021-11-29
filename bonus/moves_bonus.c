/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:03:42 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/22 19:33:50 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_sl *sl)
{
	if (sl->map[sl->p.y][sl->p.x - 1] != '1')
	{
		if (sl->pexit == 1)
			sl->map[sl->p.y][sl->p.x] = 'E';
		else
			sl->map[sl->p.y][sl->p.x] = '0';
		if (sl->map[sl->p.y][sl->p.x - 1] == 'E')
			sl->pexit = 1;
		else
			sl->pexit = 0;
		if (sl->map[sl->p.y][sl->p.x - 1] == 'C')
			sl->count++;
		sl->map[sl->p.y][sl->p.x - 1] = 'P';
		sl->p.x--;
	}
	sl->move++;
	if (sl->pexit == 1 && sl->count == sl->col)
		sl->pdir = 13;
	else
		sl->pdir = 9;
}

void	move_right(t_sl *sl)
{
	if (sl->map[sl->p.y][sl->p.x + 1] != '1')
	{
		if (sl->pexit == 1)
			sl->map[sl->p.y][sl->p.x] = 'E';
		else
			sl->map[sl->p.y][sl->p.x] = '0';
		if (sl->map[sl->p.y][sl->p.x + 1] == 'E')
			sl->pexit = 1;
		else
			sl->pexit = 0;
		if (sl->map[sl->p.y][sl->p.x + 1] == 'C')
			sl->count++;
		sl->map[sl->p.y][sl->p.x + 1] = 'P';
		sl->p.x++;
	}
	sl->move++;
	if (sl->pexit == 1 && sl->count == sl->col)
		sl->pdir = 13;
	else
		sl->pdir = 10;
}

void	move_down(t_sl *sl)
{
	if (sl->map[sl->p.y + 1][sl->p.x] != '1')
	{
		if (sl->pexit == 1)
			sl->map[sl->p.y][sl->p.x] = 'E';
		else
			sl->map[sl->p.y][sl->p.x] = '0';
		if (sl->map[sl->p.y + 1][sl->p.x] == 'E')
			sl->pexit = 1;
		else
			sl->pexit = 0;
		if (sl->map[sl->p.y + 1][sl->p.x] == 'C')
			sl->count++;
		sl->map[sl->p.y + 1][sl->p.x] = 'P';
		sl->p.y++;
	}
	sl->move++;
	if (sl->pexit == 1 && sl->count == sl->col)
		sl->pdir = 13;
	else
		sl->pdir = 11;
}

void	move_up(t_sl *sl)
{
	if (sl->map[sl->p.y - 1][sl->p.x] != '1')
	{
		if (sl->pexit == 1)
			sl->map[sl->p.y][sl->p.x] = 'E';
		else
			sl->map[sl->p.y][sl->p.x] = '0';
		if (sl->map[sl->p.y - 1][sl->p.x] == 'E')
			sl->pexit = 1;
		else
			sl->pexit = 0;
		if (sl->map[sl->p.y - 1][sl->p.x] == 'C')
			sl->count++;
		sl->map[sl->p.y - 1][sl->p.x] = 'P';
		sl->p.y--;
	}
	sl->move++;
	if (sl->pexit == 1 && sl->count == sl->col)
		sl->pdir = 13;
	else
		sl->pdir = 12;
}
