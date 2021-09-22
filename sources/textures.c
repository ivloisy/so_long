/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:33:57 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/21 23:37:34 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_path(t_sl *sl, int i)
{
	char	*s1;
	char	*s2;

	s2 = ft_itoa(i);
	if (s2 == NULL)
		return (sl->error = BASIC_ERROR);
	s1 = ft_strjoin("./textures/", s2);
	if (s1 == NULL)
		return (sl->error = BASIC_ERROR);
	sl->tp[i] = ft_strjoin(s1, ".xpm");
	if (sl->tp[i] == NULL)
		return (sl->error = BASIC_ERROR);
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (SUCCESS);
}

static int	get_tex(t_sl *sl, int i)
{
	sl->tex[i].ptr = mlx_xpm_file_to_image(sl->ptr, sl->tp[i], &sl->tex[i].w,
			&sl->tex[i].h);
	if (sl->tex[i].ptr == NULL)
		return (sl->error = TEX_ERROR);
	sl->tex[i].addr = mlx_get_data_addr(sl->tex[i].ptr, &sl->tex[i].bpp,
			&sl->tex[i].line_length, &sl->tex[i].endian);
	if (sl->tex[i].addr == NULL)
		return (sl->error = TEX_ERROR);
	return (SUCCESS);
}

int	textures(t_sl *sl)
{
	int	i;

	i = 0;
	sl->tp = (char **)malloc(sizeof(char *) * 14);
	if (sl->tp == NULL)
		return (sl->error = BASIC_ERROR);
	sl->tex = (t_img *)malloc(sizeof(t_img) * 14);
	if (sl->tex == NULL)
		return (sl->error = BASIC_ERROR);
	while (i < 14)
	{
		if (get_path(sl, i) != SUCCESS)
			return (sl->error);
		if (get_tex(sl, i) != SUCCESS)
			return (sl->error);
		i++;
	}
	return (SUCCESS);
}
