#include "filler.h"

void		print_map(t_flr *step)
{
	int		y;
	char	*line;

	y = 0;
	while (y < step->m_size_y)
	{
		line = step->map[y];
		while (*line)
		{
			if (*line == MY_HEAT)
				printf("%s%4i%s", RED, (int)*line, RESET);
			else
				printf("%4i", (int)*line);
			line++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void		print_piece(t_flr *step)
{
	int		y;

	y = 0;
	while (y < step->p_size_y)
	{
		printf("%s\n", step->piece[y]);
		y++;
	}
}

void		free_piece(t_flr *step)
{
	int		i;

	if (step->piece)
	{
		i = 0;
		while (i < step->p_size_y)
		{
			if (step->piece[i])
				free(step->piece[i]);
			i++;
		}
		free(step->piece);
		step->piece = NULL;
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

void		free_t_flr(t_flr *step)
{
	if (step->map)
	{
		free_lines_in_map(step->map, step->m_size_y);
		free(step->map);
		step->map = NULL;
	}
	free_piece(step);
}