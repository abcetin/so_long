/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:11:43 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:11:44 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "srcs/get_next_line/get_next_line.h"
# include "srcs/libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"
# include "entity.h"
# define MOVE 30
# define MOVE_BONUS 5

t_map		get_map(char *map_name);
void		check_wals(char **map, int x, int y);
void		check_args(char **map, int x, int y);
int			arg_count(char **map, char c, int x, int y);
int			key_hook(int keycode, t_solong *so_long);
int			mouse_hook(void);
void		up(t_solong *solong, int bc);
void		down(t_solong *solong, int bc);
void		left(t_solong *solong, int bc);
void		right(t_solong *solong, int bc);
void		bullet_point(int x);
int			bullet_count(t_solong *solong);
void		locations(t_solong *solong, char arg, t_location **location);
t_location	*get_arg_location(t_solong *solong, t_location *location, char arg);
int			collision(t_solong *solong, int x, int y, char arg);
int			get_block(t_solong *solong, int x, int y, char arg);
void		move(t_solong *solong, int bc, t_entity *entity);
void		move_print_shell(void);
t_entity	*player(t_solong *solong);
t_entity	*eagle(t_solong *solong);
t_entity	*wall(t_solong *solong);
t_entity	*bullet(t_solong *solong);
void		put_map(t_solong *solong, t_entity *entity);
void		position_add_list(t_location **location, float x, float y);
void		print_map(t_solong *so_long);

//---------BONUS---------//
void		bonus_up(t_solong *solong, int bc);
void		bonus_down(t_solong *solong, int bc);
void		bonus_left(t_solong *solong, int bc);
void		bonus_right(t_solong *solong, int bc);
int			bonus_key_hook(int keycode, t_solong *so_long);
int			enemy_animation(t_solong *solong);
void		move_print_screen(t_solong *solong, int is_player);
int			game_over(t_solong *solong);
void		destroy(t_solong *solong, char *arg, int bc);
t_entity	*enemy(t_solong *solong);
void		*animation(t_solong *solong, t_entity *entity,
				char *move1, char *move2);
#endif
