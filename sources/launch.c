/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:15:36 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/19 21:25:20 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	keypress(int keycode, t_sl *sl)
{
	if (keycode == 65307)
		exit_error(sl);
/*	if (keycode == 119)
		sl->forward = 1;
	if (keycode == 115)
		sl->back = 1;
	if (keycode == 97)
		sl->left = 1;
	if (keycode == 100)
		sl->right = 1;
	if (keycode == 65361)
		sl->rotatel = 1;
	if (keycode == 65363)
		sl->rotater = 1;*/
	return (SUCCESS);
}

static int	run_window(t_sl *sl)
{
	if (display(sl) != SUCCESS)
		return (sl->error);
//	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->ptr, 0, 0);
	return (SUCCESS);
}

int	launch(t_sl *sl)
{
	sl->ptr = mlx_init();
	if (sl->ptr == NULL)
		return (MLX_ERROR);
	sl->error = textures(sl);
	if (sl->error != SUCCESS)
		return (sl->error);
	sl->pdir = 9;
	sl->a = 64;
	sl->w = ft_strlen(sl->map[1]) * sl->a;
	sl->h = sl->dim.y * sl->a;
	sl->win = mlx_new_window(sl->ptr, sl->w, sl->h, "so_long");
	if (sl->win == NULL)
		return (MLX_ERROR);
/*	sl->img = new_image(sl, sl->w, sl->h);
	if (sl->img == NULL)
		return (sl->error = IMG_ERROR);
	sl->obj = new_image(sl, sl->w, sl->h);
	if (sl->obj == NULL)
		return (sl->error = IMG_ERROR);
	background(sl);*/
	mlx_hook(sl->win, 33, 1L << 0, ft_close, sl);
	mlx_hook(sl->win, 2, 1L << 0, keypress, sl);
//	mlx_hook(sl->win, 3, 1L << 1, keyrelease, sl);
	mlx_loop_hook(sl->ptr, run_window, sl);
	mlx_loop(sl->ptr);
	return (SUCCESS);
}
