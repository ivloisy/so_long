/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:40:41 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/18 18:25:36 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display(t_sl *sl)
{
	free_img(sl, sl->img);
	sl->img = new_image(sl, ft_strlen(sl->map[1]) * sl->a, sl->dim.y * sl->a);
	if (sl->img == NULL)
		return (sl->error = IMG_ERROR);
	background(sl);
	return (SUCCESS);
}
