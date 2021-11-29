/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:15:36 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/28 17:11:22 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	keypress(int keycode, t_sl *sl)
{
	if (keycode == 65307)
		exit(SUCCESS);
	if (keycode == 119 || keycode == 65362)
		move_up(sl);
	if (keycode == 115 || keycode == 65364)
		move_down(sl);
	if (keycode == 97 || keycode == 65361)
		move_left(sl);
	if (keycode == 100 || keycode == 65363)
		move_right(sl);
	return (SUCCESS);
}

static int	display(t_sl *sl)
{
	free_img(sl, sl->img);
	sl->img = new_image(sl, ft_strlen(sl->map[1]) * sl->a, sl->dim.y * sl->a);
	if (sl->img == NULL)
		return (sl->error = IMG_ERROR);
	background(sl);
	objects(sl);
	mlx_string_put(sl->ptr, sl->win, 10, 15, 0x9b8143, "MOVES :");
	mlx_string_put(sl->ptr, sl->win, 10, 30, 0x9b8143, ft_itoa(sl->move));
	if (sl->pexit == 1 && sl->count == sl->col)
		exit_error(sl);
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
	mlx_hook(sl->win, 33, 1L << 0, ft_close, sl);
	mlx_hook(sl->win, 2, 1L << 0, keypress, sl);
	mlx_loop_hook(sl->ptr, display, sl);
	mlx_loop(sl->ptr);
	return (SUCCESS);
}
