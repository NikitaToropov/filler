#include "filler.h"

void		error(t_flr *step)
{
	int		i;

	free_t_flr(step);
	write(1, "Error\n", 6);
	exit(1);
}

void			get_player(t_flr *step)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
	{
		if (line)
			free(line);
		error(step);
	}
	if (ft_strncmp(line, "$$$ exec p", 9) == 0 && step->me == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			step->me = P2_CHAR;
			step->enemy = P1_CHAR;
		}
		if (ft_strstr(line, "p1"))
		{
			step->me = P2_CHAR;
			step->enemy = P2_CHAR;
		}
	}
	else
	{
		if (line)
			free(line);
		error(step);
	}
	free(line);
}

static void		init_t_flr(t_flr *step)
{
	step->map = NULL;
	step->m_size_x = 0;
	step->m_size_y = 0;
	step->me = 0;
	step->enemy = 0;

	step->piece = NULL;
	step->p_size_x = 0;
	step->p_size_y = 0;

	step->best_summ = INF;
	step->best_x = -1;
	step->best_y = -1;
}

int				main(void)
{
	t_flr		step;

	init_t_flr(&step);
	get_player(&step);



	while (1)
	{
		get_vm_return(&map, &p);
		make_heat_map(map);
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