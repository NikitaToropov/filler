#include "filler.h"

void			get_map_size(char *line, t_map *map)
{
	int			i;
	int			tmp;

	i = 0;
	if ()
	while (line[i])
	{
		tmp = 0;
		while (is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			if (is_number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (map->map_size_y == 0)
			map->map_size_y = tmp;
		else if (map->map_size_x == 0)
			map->map_size_x = tmp;
		i++;
	}
	get_map(map);
}

void		get_vm_return(t_map *map, t_piece *p)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			fill_map_size(line, map);





			free(line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			get_piece_size(line, p);
			return (1);
		}
		else
			ft_strdel(&line);
	}
}
