/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move_count_print_shell.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:11:33 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:11:34 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_print_shell(void)
{
	static int	move;

	ft_putnbr_fd(++move, 1);
	write(1, "\n", 1);
}

void	move_print_screen(t_solong *solong, int is_player)
{
	static int	move;

	if (is_player == 1)
		mlx_string_put(solong->mlx_ptr, solong->win_ptr, 10,
			((solong->map.height + 1) * 30) + 18,
			0x00FFFFFF, ft_strjoin("Hareket : ", ft_itoa(++move)));
	else
		mlx_string_put(solong->mlx_ptr, solong->win_ptr, 10,
			((solong->map.height + 1) * 30) + 18,
			0x00FFFFFF, ft_strjoin("Hareket : ", ft_itoa(move)));
}
