/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:12:38 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:12:39 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "entity.h"

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_solong
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_entity	*player;
	t_entity	*enemy;
}	t_solong;

#endif
