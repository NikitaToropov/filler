#include "filler.h"

void		set_default_heat(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (i < map->m_size_y)
	{
		line = map->map[i];
		while(*line)
		{
			if (*line = map->me)
				*line = MY_HEAT;
			else if (*line = map->me)
				*line = 0;
			else
				*line = DEFAULT;
			line++;
		}
		i++;
	}
}

int			check_and_set_aroud(char **map, int y, int x, char h)
{
	int		i;

	i = 0;
	if (map[y + 1][x - 1] != MY_HEAT && map[y + 1][x - 1] > h && (i = 1))
		map[y + 1][x - 1] = h;
	if (map[y + 1][x] != MY_HEAT && map[y + 1][x] > h && (i = 1))
		map[y + 1][x] = h;
	if (map[y + 1][x + 1] != MY_HEAT && map[y + 1][x + 1] > h && (i = 1))
		map[y + 1][x + 1] = h;
	if (map[y][x - 1] != MY_HEAT && map[y][x - 1] > h && (i = 1))
		map[y][x - 1] = h;
	if (map[y][x + 1] != MY_HEAT && map[y][x + 1] > h && (i = 1))
		map[y][x + 1] = h;
	if (map[y - 1][x - 1] != MY_HEAT && map[y - 1][x - 1] > h && (i = 1))
		map[y - 1][x - 1] = h;
	if (map[y - 1][x] != MY_HEAT && map[y - 1][x] > h && (i = 1))
		map[y - 1][x] = h;
	if (map[y - 1][x + 1] != MY_HEAT && map[y - 1][x + 1] > h && (i = 1))
		map[y - 1][x + 1] = h;
	return (i);
}

int			set_the_heat(t_map *map, char h)
{
	int		y;
	int		x;
	char	prev;
	char	marker;

	y = 0;
	marker = 0;
	prev = h - 1;
	while (y < map->m_size_y)
	{
		x = 0;
		while (x < map->m_size_x)
			if (map->map[y][x] == prev)
				marker = check_and_set_aroud(map->map, y, x, h);
			x++;
		}
		y++;
	}
	return (marker);
}

void		init_heat_map(t_map *map)
{
	char		i;

	set_default_heat(map);
	i = 1;
	while (i < MY_HEAT && set_the_heat(map, i))
		;
}
