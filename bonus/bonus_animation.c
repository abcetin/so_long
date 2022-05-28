/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:09:22 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:09:24 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*animation(t_solong *solong, t_entity *entity, char *move1, char *move2)
{
	static int	i;
	void		*ret;

	if (i == 0 && ++i)
		ret = mlx_xpm_file_to_image
			(solong->mlx_ptr, move1,
				&entity->assets->width, &entity->assets->height);
	else
	{
		ret = mlx_xpm_file_to_image
			(solong->mlx_ptr, move2,
				&entity->assets->width, &entity->assets->height);
		i = 0;
	}
	return (ret);
}

t_location	*get_arg_location(t_solong *solong, t_location *location, char arg)
{
	int		x;
	int		y;
	t_map	map;

	x = location->x + 1;
	y = location->y;
	map = solong->map;
	while (x <= map.height)
	{
		if (map.map[y][x] == arg)
		{
			location->x = x;
			location->y = y;
			return (location);
		}
		x++;
	}
	return (0);
}
