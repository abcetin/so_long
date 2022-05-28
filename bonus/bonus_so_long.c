/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:10:59 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:11:00 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_solong *so_long)
{
	put_map(so_long, eagle(so_long));
	put_map(so_long, wall(so_long));
	put_map(so_long, bullet(so_long));
	put_map(so_long, so_long->enemy);
	put_map(so_long, so_long->player);
}

int	main(int ac, char **av)
{
	t_solong	so_long;

	if (ac == 2)
	{
		so_long.map = get_map(av[1]);
		so_long.mlx_ptr = mlx_init();
		so_long.win_ptr = mlx_new_window(so_long.mlx_ptr,
				(so_long.map.width + 1) * 30,
				(so_long.map.height + 2) * 30, "./so_long");
		so_long.player = player(&so_long);
		so_long.enemy = enemy(&so_long);
		print_map(&so_long);
		move_print_screen(&so_long, 0);
		mlx_hook(so_long.win_ptr, 2, 1L << 0, bonus_key_hook, &so_long);
		mlx_hook(so_long.win_ptr, 17, 0, mouse_hook, &so_long);
		if (arg_count(so_long.map.map, 'D',
				so_long.map.width, so_long.map.height) > 0)
			mlx_loop_hook(so_long.mlx_ptr, enemy_animation, &so_long);
		mlx_loop(so_long.mlx_ptr);
	}
	return (0);
}
