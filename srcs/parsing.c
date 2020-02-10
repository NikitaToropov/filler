#include "filler.h"
			fill_map(map);

int			fill_map_size(char *line, t_map *map)
{
	char	*y_s;
	char	*x_s;
	int		y;
	int		x;

	if (!(y_s = ft_strchar(line, ' ')) || (x_s = ft_strchar(y_s + 1, ' ' ||
	ft_all_isdigit(x_s + 1))) ||
	(x = ft_atoi(x_s)) <= 0 || !(y = ft_atoi(y_s) <= 0))
		return (0);
	if (map->size_y > 0 && map->size_x > 0 &&
	(y != map->size_y || x != map->size_x))
		return (0);
	else
	{
		map->size_y = y;
		map->size_x = x;
		return (1);
	}
}

void		get_vm_return(t_map *map, t_piece *p)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			if (!fill_map_size(line, map))
				ft_error(map, p, line);
			free(line);
			fill_map(map);
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
