/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:09:37 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:09:39 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	enemy_move(t_solong *solong, int enemy_speed)
{
	if (enemy_speed > 0)
		solong->enemy->img = animation(solong, solong->enemy,
				"./assets/enemy/enemy_right.xpm",
				"./assets/enemy/enemy_right_2.xpm");
	else
		solong->enemy->img = animation(solong, solong->enemy,
				"./assets/enemy/enemy_left.xpm",
				"./assets/enemy/enemy_left_2.xpm");
	solong->enemy->location->x += enemy_speed;
	mlx_clear_window(solong->mlx_ptr, solong->win_ptr);
	move_print_screen(solong, 0);
	print_map(solong);
	mlx_do_sync(solong->mlx_ptr);
}

int	enemy_animation(t_solong *solong)
{
	int			wall;
	static int	i;

	wall = get_block(solong, solong->enemy->location->x,
			solong->enemy->location->y, '1');
	if (game_over(solong) == 1)
		i = 2;
	else if (wall - (solong->enemy->location->x / 30) == 1)
		i = 1;
	else if (wall - (solong->enemy->location->x / 30) == 0)
		i = 0;
	if (i == 0)
		enemy_move(solong, 1);
	if (i == 1)
		enemy_move(solong, -1);
	return (0);
}
