/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:21:23 by ivloisy           #+#    #+#             */
/*   Updated: 2021/09/17 02:13:57 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keycode, t_sl sl)
{
	sl.error = NO_ERROR;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	exit_error(&sl);
	return (0);
}
