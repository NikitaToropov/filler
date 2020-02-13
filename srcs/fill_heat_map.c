#include "filler.h"

static void		set_default_heat(t_flr *step)
{
	char	*line;
	int		i;

	i = 0;
	while (i < step->m_size_y)
	{
		line = step->map[i];
		while(*line)
		{
			if (*line == step->me)
				*line = MY_HEAT;
			else if (*line == step->enemy)
				*line = 0;
			else
				*line = DEFAULT;
			line++;
		}
		i++;
	}
}

static int		set_heat_aroud(char **map, int y, int x, char h)
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

// static int			set_the_heat(t_flr *step, char heat)
static int		set_the_heat(t_flr *step, char heat)
{
	int		y;
	int		x;
	char	prev;
	char	marker;

	y = 0;
	marker = 0;
	prev = heat - 1;
	while (y < step->m_size_y)
	{
		x = 0;
		while (x < step->m_size_x)
		{
			if (step->map[y][x] == prev)
				marker = set_heat_aroud(step->map, y, x, heat);
			x++;
		}
		y++;
	}
	return (marker);
}

void		fill_heat_map(t_flr *step)
{
	char		heat;

	set_default_heat(step);
	heat = 1;
	while (heat < MY_HEAT && set_the_heat(step, heat))
		;
	print_map(step);
	print_piece(step);
}
