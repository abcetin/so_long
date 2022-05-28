/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:11:22 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:11:23 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_solong *solong, char *arg, int bc)
{
	if (arg[0] == 'E' && bc == 0)
	{
		mlx_clear_window(solong->mlx_ptr, solong->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (arg[0] == 'C' && bc--)
		arg[0] = '0';
}

int	get_block(t_solong *solong, int x, int y, char arg)
{
	t_map	map;

	map = solong->map;
	while ((x / 30) <= map.width)
	{
		if (map.map[y / 30][x / 30] == arg)
			return (x / 30);
		x++;
	}
	return (0);
}

int	collision(t_solong *solong, int x, int y, char arg)
{
	t_map	map;
	float	wall;
	float	wall2;
	int		tempy;

	map = solong->map;
	tempy = y;
	while (tempy % 30 != 0)
		tempy++;
	if (y > (map.height - 1) * 30)
		return (0);
	wall = get_block(solong, x, y, arg) - (x / (float)(30));
	wall2 = get_block(solong, x, tempy, arg) - (x / (float)30);
	if (wall < 1 || wall2 < 1)
		return (0);
	return (1);
}
