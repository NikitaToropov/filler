#include "filler.h"

void		fill_piece(t_map *map, t_piece *p)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < p->size_y && get_next_line(0, &line))
	{
		if (ft_strlen(line) != p->size_x)
			ft_error(map, p, line);
		map->map[i] = line;
	}
	if (i != p->size_y)
		ft_error(map, p, NULL);
}

void		free_piece(t_piece *p)
{
	int		i;

	if (p->piece)
	{
		i = 0;
		while (i < p->size_y)
		{
			if (p->piece[i])
				free(p->piece[i]);
			i++;
		}
		free(p->piece);
		p->piece = NULL;
	}
}

void		init_t_piece(t_piece *p)
{
	p->piece = NULL;
	p->size_x = 0;
	p->size_y = 0;
}