/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_over.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:10:21 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:10:22 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_over(t_solong *solong)
{
	int	player_y;
	int	player_y_2;

	player_y = solong->player->location->y;
	player_y_2 = player_y;
	while (player_y_2 % 30 != 0)
		player_y_2++;
	while (player_y % 30 != 0)
		player_y--;
	if (((solong->enemy->location->x - solong->player->location->x < 30)
			&& (solong->player->location->x - solong->enemy->location->x < 30)
			&& (player_y == solong->enemy->location->y))
		|| ((solong->enemy->location->x - solong->player->location->x < 30)
			&& (solong->player->location->x - solong->enemy->location->x < 30)
			&& (player_y_2 == solong->enemy->location->y)))
	{
		mlx_clear_window(solong->mlx_ptr, solong->win_ptr);
		mlx_string_put(solong->mlx_ptr, solong->win_ptr,
			((solong->map.width / 2) * 30) - 10,
			(solong->map.height / 2) * 30 + 35,
			0x00FFFFFF, "GAME OVER PRESS TO ESC");
		return (1);
	}
	return (0);
}
