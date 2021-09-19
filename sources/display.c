/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:40:41 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/19 21:21:52 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display(t_sl *sl)
{
	free_img(sl, sl->img);
	sl->img = new_image(sl, ft_strlen(sl->map[1]) * sl->a, sl->dim.y * sl->a);
	if (sl->img == NULL)
		return (sl->error = IMG_ERROR);
	background(sl);
	objects(sl);
/*	sl->y = -1;
	a = 0;
	b = 0;
	while (++sl->y < sl->img->h)
	{
		if (b == sl->a)
			b = 0;
		sl->x = -1;
		while (++sl->x < sl->img->w)
		{
			if (a == sl->a)
				a = 0;
			draw_col(sl, a, b);
			a++;
		}
		b++;
	}*/
	return (SUCCESS);
}
