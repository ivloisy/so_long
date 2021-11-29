/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:15:51 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/22 19:09:35 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_obj(t_sl *sl, int a, int b)
{
	int	color;

	color = 0;
	if (sl->map[sl->y / sl->a][sl->x / sl->a] == 'C')
		color = get_pixel(&sl->tex[8], a / (sl->a / sl->tex[8].w), b
				/ (sl->a / sl->tex[8].h));
	else if (sl->map[sl->y / sl->a][sl->x / sl->a] == 'P')
	{
		if (sl->pexit == 1)
			color = get_pixel(&sl->tex[7], a / (sl->a / sl->tex[7].w), b
					/ (sl->a / sl->tex[7].h));
		if (get_pixel(&sl->tex[sl->pdir], a
				/ (sl->a / sl->tex[sl->pdir].w), b
				/ (sl->a / sl->tex[sl->pdir].h)) != 0)
			color = get_pixel(&sl->tex[sl->pdir], a
					/ (sl->a / sl->tex[sl->pdir].w), b
					/ (sl->a / sl->tex[sl->pdir].h));
	}
	if (color != 0)
		ft_pixel_put(sl->img, sl->x, sl->y, color);
	color = 0;
}

void	objects(t_sl *sl)
{
	int	a;
	int	b;

	sl->y = -1;
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
			draw_obj(sl, a, b);
			a++;
		}
		b++;
	}
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->ptr, 0, 0);
}
