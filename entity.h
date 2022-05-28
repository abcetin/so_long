/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:12:48 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:12:49 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "so_long.h"
# include "struct.h"

typedef struct s_location
{
	int					x;
	int					y;
	struct s_location	*next;
}	t_location;

typedef struct s_assets
{
	char	*path;
	int		width;
	int		height;
}				t_assets;

typedef struct s_entity
{
	t_assets	*assets;
	t_location	*location;
	void		*img;
}				t_entity;

#endif
