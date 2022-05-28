/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_create_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:11:54 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:11:55 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locations(t_solong *solong, char arg, t_location **location)
{
	t_map	map;
	int		x;
	int		y;

	y = 0;
	map = solong->map;
	while (y <= map.height)
	{
		x = 0;
		while (x <= map.width)
		{
			if (map.map[y][x] == arg)
				position_add_list(location, x * 30, y * 30);
			x++;
		}
		y++;
	}
}

void	put_map(t_solong *solong, t_entity *entity)
{
	t_location	*temp;

	temp = (t_location *)malloc(sizeof(t_location));
	if (!temp)
		return ;
	temp = entity->location;
	while (entity->location)
	{
		mlx_put_image_to_window
			(solong->mlx_ptr, solong->win_ptr, entity->img,
				entity->location->x, entity->location->y);
		entity->location = entity->location->next;
	}
	entity->location = temp;
}
