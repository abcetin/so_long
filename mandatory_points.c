/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:14:03 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:14:04 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bullet_count(t_solong *solong)
{
	int		y;
	int		x;
	int		i;
	t_map	map;

	map = solong->map;
	y = 0;
	i = 0;
	while (y <= map.height)
	{
		x = 0;
		while (x <= map.width)
		{
			if (map.map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}
