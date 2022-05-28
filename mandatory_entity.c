/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_entity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:51 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:13:54 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_entity	*player(t_solong *solong)
{
	t_entity	*player;

	player = (t_entity *)malloc(sizeof(t_entity));
	player->assets = (t_assets *)malloc(sizeof(t_assets));
	player->location = (t_location *)malloc(sizeof(t_assets));
	if (!player || !player->assets || !player->location)
		return (NULL);
	player->assets->path = "./assets/player/player_right.xpm";
	player->assets->height = 30;
	player->assets->width = 30;
	player->location = NULL;
	locations(solong, 'P', &player->location);
	player->img = mlx_xpm_file_to_image(solong->mlx_ptr, player->assets->path,
			&player->assets->width, &player->assets->height);
	return (player);
}

t_entity	*eagle(t_solong *solong)
{
	t_entity	*eagle;

	eagle = (t_entity *)malloc(sizeof(t_entity));
	eagle->assets = (t_assets *)malloc(sizeof(t_assets));
	eagle->location = (t_location *)malloc(sizeof(t_assets));
	if (!eagle || !eagle->assets || !eagle->location)
		return (NULL);
	eagle->assets->path = "./assets/eagle/eagle.xpm";
	eagle->assets->height = 30;
	eagle->assets->width = 30;
	eagle->location = NULL;
	locations(solong, 'E', &eagle->location);
	eagle->img = mlx_xpm_file_to_image(solong->mlx_ptr, eagle->assets->path,
			&eagle->assets->width, &eagle->assets->height);
	return (eagle);
}

t_entity	*wall(t_solong *solong)
{
	t_entity	*wall;

	wall = (t_entity *)malloc(sizeof(t_entity));
	wall->assets = (t_assets *)malloc(sizeof(t_assets));
	wall->location = (t_location *)malloc(sizeof(t_assets));
	if (!wall || !wall->assets || !wall->location)
		return (NULL);
	wall->assets->path = "./assets/wall/wall.xpm";
	wall->assets->height = 30;
	wall->assets->width = 30;
	wall->location = NULL;
	locations(solong, '1', &wall->location);
	wall->img = mlx_xpm_file_to_image(solong->mlx_ptr, wall->assets->path,
			&wall->assets->width, &wall->assets->height);
	return (wall);
}

t_entity	*bullet(t_solong *solong)
{
	t_entity	*bullet;

	bullet = (t_entity *)malloc(sizeof(t_entity));
	bullet->assets = (t_assets *)malloc(sizeof(t_assets));
	bullet->location = (t_location *)malloc(sizeof(t_location));
	if (!bullet || !bullet->assets || !bullet->location)
		return (NULL);
	bullet->assets->path = "./assets/bullet/bullet.xpm";
	bullet->assets->height = 30;
	bullet->assets->width = 30;
	bullet->location = NULL;
	locations(solong, 'C', &bullet->location);
	bullet->img = mlx_xpm_file_to_image(solong->mlx_ptr, bullet->assets->path,
			&bullet->assets->width, &bullet->assets->height);
	return (bullet);
}
