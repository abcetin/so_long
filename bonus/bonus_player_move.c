/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:10:00 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:10:01 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_up(t_solong *solong, int bc)
{
	int	x;
	int	y;
	int	enemy_count;

	x = solong->player->location->x;
	y = solong->player->location->y - MOVE_BONUS;
	enemy_count = arg_count(solong->map.map, 'D',
			solong->map.width, solong->map.height);
	if (enemy_count > 0 && game_over(solong) == 1)
		return ;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = animation(solong, solong->player,
			"./assets/player/player_up.xpm",
			"./assets/player/player_up_2.xpm");
	solong->player->location->y -= MOVE_BONUS;
	move(solong, bc, solong->player);
}

void	bonus_down(t_solong *solong, int bc)
{
	int	x;
	int	y;
	int	enemy_count;

	y = solong->player->location->y + MOVE_BONUS;
	x = solong->player->location->x;
	enemy_count = arg_count(solong->map.map, 'D',
			solong->map.width, solong->map.height);
	if (enemy_count > 0 && game_over(solong) == 1)
		return ;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = animation(solong, solong->player,
			"./assets/player/player_down.xpm",
			"./assets/player/player_down_2.xpm");
	solong->player->location->y += MOVE_BONUS;
	move(solong, bc, solong->player);
}

void	bonus_left(t_solong *solong, int bc)
{
	int	x;
	int	y;
	int	enemy_count;

	y = solong->player->location->y;
	x = solong->player->location->x - MOVE_BONUS;
	enemy_count = arg_count(solong->map.map, 'D',
			solong->map.width, solong->map.height);
	if (enemy_count > 0 && game_over(solong) == 1)
		return ;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = animation(solong, solong->player,
			"./assets/player/player_left.xpm",
			"./assets/player/player_left_2.xpm");
	solong->player->location->x -= MOVE_BONUS;
	move(solong, bc, solong->player);
}

void	bonus_right(t_solong *solong, int bc)
{
	int	x;
	int	y;
	int	enemy_count;

	y = solong->player->location->y;
	x = solong->player->location->x + MOVE_BONUS;
	enemy_count = arg_count(solong->map.map, 'D',
			solong->map.width, solong->map.height);
	if (enemy_count > 0 && game_over(solong) == 1)
		return ;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = animation(solong, solong->player,
			"./assets/player/player_right.xpm",
			"./assets/player/player_right_2.xpm");
	solong->player->location->x += MOVE_BONUS;
	move(solong, bc, solong->player);
}
