#include "filler.h"


void		ft_error(t_map *map, t_piece *p, char *line)
{
	free_piece(p);
	free_map(map);
	if (line)
		free(line);
	exit(1);
}

void			get_player(t_map *map, char *p1_abc, char *p2_abc)
{
	char		*line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			map->player = 2;
			map->my_abc = p2_abc;
			map->en_abc = p1_abc;
		}
		if (ft_strstr(line, "p1"))
		{
			map->player = 1;
			map->my_abc = p1_abc;
			map->en_abc = p2_abc;
		}
	}
	free(line);
}

void		init_struct(t_map *map, t_piece *p)
{
	map->map = NULL;
	map->player = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->best_summ = INF;
	map->best_x = -1;
	map->best_y = -1;

	p->piece = NULL;
	p->size_x = 0;
	p->size_y = 0;
}

int				main(void)
{
	t_map		map;
	t_piece		p;

	init_struct(&map, &p);
	get_player(&map, P1_ABC, P2_ABC);
	while (1)
	{
		get_vm_return(&map, &p);









		if (play(map, p) == 1)
		{
			if (last_try(map, p) == 1)
			{
				print_result(p, map);
				exit(1);
			}
		}
	}
	free(p.piece);
	return (0);
}
