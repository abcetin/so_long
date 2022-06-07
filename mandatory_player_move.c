/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_player_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:12:02 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:12:03 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_solong *solong, int bc)
{
	int	x;
	int	y;

	x = solong->player->location->x;
	y = solong->player->location->y - MOVE;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = mlx_xpm_file_to_image(solong->mlx_ptr,
			"./assets/player/player_up.xpm",
			&solong->player->assets->width,
			&solong->player->assets->height);
	solong->player->location->y -= MOVE;
	move(solong, bc, solong->player);
	move_print_shell();
}

void	down(t_solong *solong, int bc)
{
	int	x;
	int	y;

	y = solong->player->location->y + MOVE;
	x = solong->player->location->x;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = mlx_xpm_file_to_image(solong->mlx_ptr,
			"./assets/player/player_down.xpm",
			&solong->player->assets->width,
			&solong->player->assets->height);
	solong->player->location->y += MOVE;
	move(solong, bc, solong->player);
	move_print_shell();
	//free(solong->player->img);
}

void	left(t_solong *solong, int bc)
{
	int	x;
	int	y;

	y = solong->player->location->y;
	x = solong->player->location->x - MOVE;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = mlx_xpm_file_to_image(solong->mlx_ptr,
			"./assets/player/player_left.xpm",
			&solong->player->assets->width,
			&solong->player->assets->height);
	solong->player->location->x -= MOVE;
	move(solong, bc, solong->player);
	move_print_shell();
	//free(solong->player->img);
}

void	right(t_solong *solong, int bc)
{
	int	x;
	int	y;

	y = solong->player->location->y;
	x = solong->player->location->x + MOVE;
	if (collision(solong, x, y, '1') == 0)
		return ;
	solong->player->img = mlx_xpm_file_to_image(solong->mlx_ptr,
			"./assets/player/player_right.xpm",
			&solong->player->assets->width,
			&solong->player->assets->height);
	solong->player->location->x += MOVE;
	move(solong, bc, solong->player);
	move_print_shell();
	//free(solong->player->img);
}
