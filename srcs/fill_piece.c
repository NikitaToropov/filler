#include "filler.h"
static void		fill_piece_size(t_flr *step)
{
	char		*line;
	char		*y_str;
	char		*x_str;
	int			y;
	int			x;

	y = 0;
	x = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0 || ft_strncmp(line, "Piece", 4) ||
	!(y_str = ft_strchr(line, ' ')) || !(x_str = ft_strchr(y_str + 1, ' ')) ||
	ft_strchr(x_str + 1, ' ') ||
	(y = ft_atoi(y_str)) < 1 || (x = ft_atoi(x_str)) < 1 ||
	(step->p_size_y > 0 && y != step->m_size_y) ||
	(step->p_size_x > 0 && x != step->m_size_x))
	{
printf("fill_piece_size/ Piece line\n");
		error(step, line);
	}

	step->p_size_y = y;
	step->p_size_x = x;
	if (step->p_size_y > step->m_size_y || step->p_size_x > step->m_size_x)
	{
printf("fill_piece_size/ piece bigger then map\n");
		error(step, line);
	}

	free(line);
}

static void		check_piece_line(t_flr *step, char *line)
{
	int			i;

	i = 0;
	
	if (line && ft_strlen(line) == (size_t)step->p_size_x)
	{
		while (line[i])
		{
			if (!ft_strchr(".*", line[i]))
			{
printf("check_piece_line | proble %s\n", &line[i]);
				error(step, line);
			}
			i++;
		}
	}
printf("check_piece_line | to much problems\n");
	error(step, line);
}

void			fill_piece(t_flr *step)
{
	char	*line;
	int		i;

	fill_piece_size(step);
	i = 0;
	line = NULL;
	while (i < step->p_size_y && get_next_line(0, &line))
	{
		check_piece_line(step, line);
		step->piece[i] = line;
		i++;
	}
	if (i != step->p_size_y)
	{
printf("fill_piece/ i != step->p_size_y\n");
printf("fill_map/ %i != %i\n", i, step->p_size_y);
		error(step, NULL);
	}
}