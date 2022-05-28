/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:36 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:13:37 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_solong *solong, int bc, t_entity *entity)
{
	t_map	map;
	int		x;
	int		y;

	map = solong->map;
	x = entity->location->x;
	y = entity->location->y;
	if (map.map[y / 30][x / 30] == 'C' || map.map[y / 30][x / 30] == 'E')
		destroy(solong, &map.map[y / 30][x / 30], bc);
	mlx_clear_window(solong->mlx_ptr, solong->win_ptr);
	print_map(solong);
	move_print_screen(solong, 1);
}
