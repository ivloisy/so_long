/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:15:36 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/17 02:35:10 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	run_window(t_sl *sl)
{
	if (display(sl) != SUCCESS)
		return (sl->error);
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->ptr, 0, 0);
	return (SUCCESS);
}

int	launch(t_sl *sl)
{
	int		x;
	int		y;

	sl->ptr = mlx_init();
	if (sl->ptr == NULL)
		return (MLX_ERROR);
	sl->error = textures(sl);
	if (sl->error != SUCCESS)
		return (sl->error);
/*	mlx_get_screen_size(sl->ptr, &x, &y);
	if (sl->w > x)
		sl->w = x;
	if (sl->h > y)
		sl->h = y;*/
	x = ft_strlen(sl->map[1]) * 64;
	y = sl->dim.y * 64;
	sl->win = mlx_new_window(sl->ptr, x, y, "so_long");
	if (sl->win == NULL)
		return (MLX_ERROR);
	mlx_hook(sl->win, 33, 1L << 0, ft_close, sl);
/*	mlx_hook(sl->win, 2, 1L << 0, keypress, sl);
	mlx_hook(sl->win, 3, 1L << 1, keyrelease, sl);*/
	mlx_loop_hook(sl->ptr, run_window, sl);
	mlx_loop(sl->ptr);
	return (SUCCESS);
}
