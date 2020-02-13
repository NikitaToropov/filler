#include "filler.h"
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include "libft.h"

void			error(t_flr *step, char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	free_t_flr(step);
	write(1, "Error\n", 6);
	exit(1);
}

static void		get_player(t_flr *step)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		error(step, line);
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
		free(line);
	}
	else
		error(step, line);
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

void			parse_input(t_flr *step)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		fill_map_size(step, line);
		fill_map(step);
		fill_piece(step);
	}
}

int				main(void)
{
	// int			fd;
	// char		*line;
	// int			l;

	// fd = open("txt.txt", O_RDWR | O_APPEND);
	// while (get_next_line(0, &line))
	// {
	// 	l = ft_strlen(line);
	// 	write(fd, line, l);
	// 	write(fd, "\n", 1);
	// }
	// close(fd);
	t_flr		step;

	init_t_flr(&step);
	get_player(&step);
	while (1)
	{
		parse_input(&step);
		fill_heat_map(&step);
		// find_best_heat_solution();

	}
	free_t_flr(&step);
	return (0);
}	