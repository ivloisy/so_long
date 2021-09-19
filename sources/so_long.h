/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:26:58 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/18 20:17:21 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include "./get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

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
/*	FLAG_ERROR,
	NOT_VALID_FILE_ERROR,
	NOT_VALID_R_ERROR,
	NOT_VALID_NO_ERROR,
	NOT_VALID_SO_ERROR,
	NOT_VALID_WE_ERROR,
	NOT_VALID_EA_ERROR,
	NOT_VALID_S_ERROR,
	NOT_VALID_F_ERROR,
	NOT_VALID_F_C_ERROR,
	NOT_VALID_F_P_ERROR,
	NOT_VALID_C_ERROR,
	NOT_VALID_C_C_ERROR,
	NOT_VALID_C_P_ERROR,
	NB_PLAY_ERROR,
	TEX_F_ERROR,
	TEX_C_ERROR*/
}t_error;

void	exit_error(t_sl *sl);
int		check_map(t_sl *sl);
int		launch(t_sl *sl);
int		textures(t_sl *sl);
int		ft_close(int keycode, t_sl sl);
int		display(t_sl *sl);
void	ft_pixel_put(t_img *img, int x, int y, int color);
t_img	*new_image(t_sl *sl, int x, int y);
void	free_img(t_sl *sl, t_img *img);
int		get_pixel(t_img *img, int x, int y);
void	background(t_sl *sl);

#endif