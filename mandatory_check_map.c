/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_check_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:02 by acetin            #+#    #+#             */
/*   Updated: 2022/05/23 14:13:03 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	x_count(char *map_name)
{
	int			x;
	int			i;
	char		*str;
	int			fd;

	x = -1;
	i = 1;
	str = (char *)calloc(sizeof(char), 1);
	if (!str)
		return (0);
	fd = open(map_name, O_RDONLY);
	while (i != 0)
	{
		i = read(fd, str, 1);
		if (ft_strchr(str, '\n'))
			break ;
		x++;
	}
	free(str);
	close(fd);
	return (x);
}

static int	y_count(char *map_name)
{
	int		i;
	int		y;
	int		fd;

	i = 1;
	y = -1;
	fd = open(map_name, O_RDONLY);
	while (get_next_line(fd))
		y++;
	close(fd);
	return (y);
}

void	check_map_name(char *map_name)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "ber";
	j = 0;
	while (map_name[i] != '.')
		i++;
	while (map_name[i] != '\0')
	{
		if (!ft_strchr(&map_name[i], set[j]))
		{
			printf("\033[0;31mMap uzantısı hatalı!!!\n");
			exit(EXIT_FAILURE);
		}
		i++;
		j++;
	}
}

t_map	get_map(char *map_name)
{
	int		fd;
	t_map	map;
	int		i;

	check_map_name(map_name);
	fd = open(map_name, O_RDONLY);
	map.width = x_count(map_name);
	map.height = y_count(map_name);
	map.map = (char **)calloc(sizeof(char *), map.height * map.width);
	i = -1;
	while (++i <= map.height)
		map.map[i] = get_next_line(fd);
	close(fd);
	check_wals(map.map, map.width, map.height);
	check_args(map.map, map.width, map.height);
	return (map);
}

void	check_wals(char **map, int x, int y)
{
	int	temp_x;
	int	temp_y;

	temp_y = 0;
	while (temp_y <= y)
	{
		temp_x = 0;
		while (temp_x <= x)
		{
			if ((temp_y == 0 || temp_y == y) && (map[temp_y][temp_x] != '1'))
			{
				printf("\033[0;31mMap Üst Alt Sınırda Hata!!!\n");
				exit(EXIT_FAILURE);
			}
			else if ((temp_x == 0 || temp_x == x)
				&& (map[temp_y][temp_x] != '1'))
			{
				printf("\033[0;31mMap Sağ Sol Sınırda Hata!!!\n");
				exit(EXIT_FAILURE);
			}
			temp_x++;
		}
		temp_y++;
	}
}
