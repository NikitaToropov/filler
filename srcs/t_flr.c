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
	}
	printf("\n");
}

void		print_piece(t_flr *step)
{
	int		y;
	char	*line;

	y = 0;
	while (y < step->p_size_y)
	{
		printf("%s\n", step->piece[y]);
		y++;
	}
}


// // void		fill_map(t_map *map, t_piece *p)
// void		fill_map(t_flr *step)
// {
// 	char	*line;
// 	int		i;

// 	line = NULL;
// 	if (!get_next_line(0, &line) || ft_strlen(line) <= X_CONST ||
// 	ft_all_isdigit(line + X_CONST) || !ft_strncmp(line, "    ", 3))
// 		ft_error(map, p, line);
// 	free(line);
// 	i = 0;
// 	while (i < map->size_y && get_next_line(0, &line))
// 	{
// 		if (i != ft_atoi(line) || ft_strlen(line + X_CONST) != map->size_x)
// 			ft_error(map, p, line);
// 		map->map[i] = line + X_CONST;
// 	}
// }

// void		fill_piece(t_map *map, t_piece *p)
// {
// 	char	*line;
// 	int		i;

// 	line = NULL;
// 	i = 0;
// 	while (i < p->size_y && get_next_line(0, &line))
// 	{
// 		if (ft_strlen(line) != p->size_x)
// 			ft_error(map, p, line);
// 		map->map[i] = line;
// 	}
// 	if (i != p->size_y)
// 		ft_error(map, p, NULL);
// }

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