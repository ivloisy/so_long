/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:04:42 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/17 15:14:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + (x * \
						(img->bpp / 8)))));
}

void	free_img(t_sl *sl, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(sl->ptr, img->ptr);
		free(img);
		img = NULL;
	}
}

t_img	*new_image(t_sl *sl, int x, int y)
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
