/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:10:12 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:10:14 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_entity	*enemy(t_solong *solong)
{
	t_entity	*enemy;

	enemy = (t_entity *)malloc(sizeof(t_entity));
	enemy->assets = (t_assets *)malloc(sizeof(t_assets));
	enemy->location = (t_location *)malloc(sizeof(t_location));
	if (!enemy || !enemy->assets || !enemy->location)
		return (NULL);
	enemy->assets->path = "./assets/enemy/enemy_right.xpm";
	enemy->assets->height = 30;
	enemy->assets->width = 30;
	enemy->location = NULL;
	locations(solong, 'D', &enemy->location);
	enemy->img = mlx_xpm_file_to_image(solong->mlx_ptr, enemy->assets->path,
			&enemy->assets->width, &enemy->assets->height);
	return (enemy);
}
