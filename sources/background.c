/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:23:49 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/21 07:29:37 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	draw_exit(t_sl *sl, int a, int b, int c)
{
	int	color;

	color = c;
	if (sl->map[(sl->y / sl->a)][sl->x / sl->a] == 'E'
			&& get_pixel(&sl->tex[7], a / (sl->a / sl->tex[7].w), b
			/ (sl->a / sl->tex[7].h)) != 0)
		color = get_pixel(&sl->tex[7], a / (sl->a / sl->tex[7].w), b
				/ (sl->a / sl->tex[7].h));
	return (color);
}

static int	draw_bath(t_sl *sl, int a, int b)
{
	int	color;

	if (sl->map[(sl->y / sl->a) + 1][sl->x / sl->a] == '1'
		&& sl->map[(sl->y / sl->a) - 1][sl->x / sl->a] == '1')
		color = get_pixel(&sl->tex[6], a / (sl->a / sl->tex[6].w), b
				/ (sl->a / sl->tex[6].h));
	else if (sl->map[(sl->y / sl->a) - 1][sl->x / sl->a] == '1')
		color = get_pixel(&sl->tex[5], a / (sl->a / sl->tex[5].w), b
				/ (sl->a / sl->tex[5].h));
	else if (sl->map[(sl->y / sl->a) + 1][sl->x / sl->a] == '1')
		color = get_pixel(&sl->tex[4], a / (sl->a / sl->tex[4].w), b
				/ (sl->a / sl->tex[4].h));
	else
		color = get_pixel(&sl->tex[3], a / (sl->a / sl->tex[3].w), b
				/ (sl->a / sl->tex[3].h));
	return (color);
}

static void	draw_wall(t_sl *sl, int a, int b)
{
	int	color;

	if (sl->map[sl->y / sl->a][sl->x / sl->a] == '1')
	{
		if (sl->map[(sl->y / sl->a) + 1] == NULL)
			color = get_pixel(&sl->tex[2], a / (sl->a / sl->tex[2].w), b
					/ (sl->a / sl->tex[2].h));
		else if (sl->map[(sl->y / sl->a) + 1][sl->x / sl->a] && ft_strchr("0CEP"
				, sl->map[(sl->y / sl->a) + 1][sl->x / sl->a]))
			color = get_pixel(&sl->tex[1], a / (sl->a / sl->tex[1].w), b
					/ (sl->a / sl->tex[1].h));
		else
			color = get_pixel(&sl->tex[0], a / (sl->a / sl->tex[0].w), b
					/ (sl->a / sl->tex[0].h));
	}
	else
	{
		color = draw_bath(sl, a, b);
		color = draw_exit(sl, a, b, color);
	}
	if (color != 0)
		ft_pixel_put(sl->img, sl->x, sl->y, color);
	color = 0;
}

void	background(t_sl *sl)
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
			draw_wall(sl, a, b);
			a++;
		}
		b++;
	}
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->ptr, 0, 0);
}
