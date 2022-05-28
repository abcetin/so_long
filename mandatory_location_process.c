/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_location_process.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:14 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:13:15 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_location	*ft_lstlast2(t_location *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	position_add_list(t_location **location, float x, float y)
{
	t_location	*location2;
	t_location	*data;

	data = (t_location *)malloc(sizeof(t_location));
	if (!data)
		return ;
	data->x = x;
	data->y = y;
	data->next = NULL;
	if (!*location)
	{
		*location = data;
		return ;
	}
	location2 = ft_lstlast2(*location);
	location2 -> next = data;
}
