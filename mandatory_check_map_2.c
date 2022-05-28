/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_check_map_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:27 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:13:28 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arg_count(char **map, char c, int x, int y)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	ret = 0;
	while (i <= y)
	{
		j = 0;
		while (j <= x)
		{
			if (map[i][j] == c)
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

static void	check_arg_2(char **map, int x, int y)
{
	char	*set;
	int		i;
	int		j;

	i = 0;
	set = "10CEPD";
	while (i <= y)
	{
		j = 0;
		while (j <= x)
		{
			if (!ft_strchr(set, map[i][j]))
			{
				printf("\033[0;31mTANIMSIZ ARGÜMAN!!!\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_args(char **map, int x, int y)
{
	int		zero;
	int		c;
	int		e;
	int		p;

	check_arg_2(map, x, y);
	c = arg_count(map, 'C', x, y);
	e = arg_count(map, 'E', x, y);
	p = arg_count(map, 'P', x, y);
	zero = arg_count(map, '0', x, y);
	if ((c == 0) || (p == 0 || p > 1) || (e == 0 || e > 1) || (zero == 0))
	{
		printf("\033[0;31mEksik Ya Da Hatalı Argüman Sayısı!!!\n");
		exit(EXIT_FAILURE);
	}
}
