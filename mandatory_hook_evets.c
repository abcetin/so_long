/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_hook_evets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:12:14 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:12:15 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_solong *so_long)
{
	int	bc;

	bc = bullet_count(so_long);
	if (keycode == 53)
	{
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13)
		up(so_long, bc);
	if (keycode == 0)
		left(so_long, bc);
	if (keycode == 1)
		down(so_long, bc);
	if (keycode == 2)
		right(so_long, bc);
	return (0);
}

int	mouse_hook(void)
{
	exit (EXIT_SUCCESS);
	return (0);
}
