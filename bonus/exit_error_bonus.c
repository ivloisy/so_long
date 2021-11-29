/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:20:12 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/28 17:07:38 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_error(int x)
{
	if (x == 3)
		ft_putstr_fd("The number of arguments is not valid.", 1);
	else if (x == 4)
		ft_putstr_fd("It is not a .ber file.", 1);
	else if (x == 5)
		ft_putstr_fd("The function read did not works.", 1);
	else if (x == 6)
		ft_putstr_fd("It is not a valid map.", 1);
	else if (x == 7)
		ft_putstr_fd("The map is not a rectangle.", 1);
	else if (x == 8)
		ft_putstr_fd("The number of players, collectives or exits.", 1);
	else if (x == 9)
		ft_putstr_fd("MLX.", 1);
	else if (x == 10)
		ft_putstr_fd("Textures not loaded.", 1);
	else if (x == 11)
		ft_putstr_fd("Image not loaded.", 1);
}

void	exit_error(t_sl *sl)
{
	if (sl->error != NO_ERROR && sl->error != BASIC_ERROR)
	{
		if (sl->error != 1)
		{
			ft_putstr_fd("Error\n", 1);
			ft_putnbr_fd(sl->error, 1);
			ft_putstr_fd(" : ", 1);
			ft_putchar_fd('\n', 1);
		}
		if (sl->error > 2)
		{
			put_error(sl->error);
			ft_putchar_fd('\n', 1);
		}
	}
	if (sl->error == BASIC_ERROR)
		perror("Error\nerrno ");
	exit(EXIT_FAILURE);
}

int	ft_close(t_sl sl)
{
	(void)sl;
	exit(SUCCESS);
	return (0);
}
