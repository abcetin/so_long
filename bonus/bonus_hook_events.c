/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hook_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:09:49 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:09:51 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bonus_key_hook(int keycode, t_solong *so_long)
{
	int	bc;

	bc = bullet_count(so_long);
	if (keycode == 53)
	{
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13)
		bonus_up(so_long, bc);
	if (keycode == 0)
		bonus_left(so_long, bc);
	if (keycode == 1)
		bonus_down(so_long, bc);
	if (keycode == 2)
		bonus_right(so_long, bc);
	return (0);
}

int	mouse_hook(void)
{
	exit (0);
	return (0);
}
