/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:40:41 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/17 04:22:50 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static t_img	*new_image(t_sl *sl, int x, int y)
{
	t_img	*img;
	
	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_new_image(sl->ptr, x, y);
	if (img->ptr == NULL)
		return (NULL);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_length,
			&img->endian);
	if (img->addr == NULL)
		return (NULL);
	img->w = x;
	img->h = y;
	return (img);
}

static void	background(t_sl *sl)
{
	int	x;
	int	y;
	int	color;
	
	y = 0;
	//while (y < sl->img->h)
	while (y < 32)
	{
		x = 0;
	//	while (x < sl->img->w)
		while (x < 32)
		{
			//if (sl->map[y / 64][x / 64] == '1')
			color = sl->tex[0].addr[x * y];
			ft_pixel_put(sl->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	display(t_sl *sl)
{
	sl->img = new_image(sl, ft_strlen(sl->map[1]) * 64, sl->dim.y * 64);
	if (sl->img == NULL)
		return (sl->error = IMG_ERROR);
	background(sl);
	return (SUCCESS);
}