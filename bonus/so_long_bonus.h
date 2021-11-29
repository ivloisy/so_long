/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:26:58 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/22 19:15:26 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "./get_next_line_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}t_img;

typedef struct s_sl
{
	void	*ptr;
	void	*win;
	int		error;
	char	**map;
	int		m;
	int		player;
	t_pos	p;
	int		pdir;
	int		pexit;
	int		col;
	t_pos	*c;
	int		exit;
	t_pos	*e;
	t_pos	dim;
	t_img	*tex;
	char	**tp;
	t_img	*img;
	int		w;
	int		h;
	int		a;
	int		x;
	int		y;
	t_img	*obj;
	int		count;
	int		move;
}t_sl;

typedef enum e_error
{
	NO_ERROR,
	SUCCESS,
	BASIC_ERROR,
	NB_ARG_ERROR,
	FILE_TYPE_ERROR,
	READ_ERROR,
	NOT_VALID_M_ERROR,
	NOT_RECT_ERROR,
	NB_CEP_ERROR,
	MLX_ERROR,
	TEX_ERROR,
	IMG_ERROR
}t_error;

void	exit_error(t_sl *sl);
int		check_map(t_sl *sl);
int		launch(t_sl *sl);
int		textures(t_sl *sl);
int		ft_close(t_sl sl);
void	ft_pixel_put(t_img *img, int x, int y, int color);
t_img	*new_image(t_sl *sl, int x, int y);
void	free_img(t_sl *sl, t_img *img);
int		get_pixel(t_img *img, int x, int y);
void	background(t_sl *sl);
void	objects(t_sl *sl);
void	move_up(t_sl *sl);
void	move_down(t_sl *sl);
void	move_right(t_sl *sl);
void	move_left(t_sl *sl);

#endif