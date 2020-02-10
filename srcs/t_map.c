#include "filler.h"

void		fill_map(t_map *map, t_piece *p)
{
	char	*line;
	int		i;

	line = NULL;
	if (!get_next_line(0, &line) || ft_strlen(line) <= X_CONST ||
	ft_all_isdigit(line + X_CONST) || !ft_strncmp(line, "    ", 3))
		ft_error(map, p, line);
	free(line);
	i = 0;
	while (i < map->size_y && get_next_line(0, &line))
	{
		if (i != ft_atoi(line) || ft_strlen(line + X_CONST) != map->size_x)
			ft_error(map, p, line);
		map->map[i] = line + X_CONST;
	}
}

void		free_lines_in_map(char **map, int size_y)
{
	int		i;

	if(map)
	{
		i = 0;
		while (i < size_y)
		{
			if ((map[i] - X_CONST))
				free((map[i] - X_CONST));
			map[i++] = NULL;
		}
	}
}

void		free_map(t_map *map)
{
	free_lines (map->map, map->size_y);
	free(map->map);
	map->map = NULL;
}

void		init_t_map(t_map *map)
{
	map->map = NULL;
	map->size_x = 0;
	map->size_y = 0;
	map->player = 0;

	map->best_summ = INF;
	map->best_x = -1;
	map->best_y = -1;

	map->my_abc = NULL;
	map->en_abc = NULL;
}