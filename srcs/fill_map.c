#include "filler.h"


void		fill_map_size(t_flr *step, char *line)
{
	char		*y_str;
	char		*x_str;
	int			y;
	int			x;

	if (ft_strncmp(line, "Plateau", 6) || !(y_str = ft_strchr(line, ' ')) ||
	!(x_str = ft_strchr(y_str + 1, ' ')) || ft_strchr(x_str + 1, ' ') ||
	(y = ft_atoi(y_str)) < 1 || (x = ft_atoi(x_str)) < 1 ||
	(step->m_size_y > 0 && y != step->m_size_y) ||
	(step->m_size_x > 0 && x != step->m_size_x))
	{
printf("fill_map_size/ Plateau line\n");
		error(step, line);
	}

	step->m_size_y = y;
	step->m_size_x = x;
	free(line);

	if (get_next_line(0, &line) <= 4 || ft_strncmp(line, "    ", 3) ||
	!ft_all_isdigit(line + 4))
	{
printf("fill_map_size/ digits line\n");
		error(step, line);
	}
	free(line);
}

static void		check_map_line(t_flr *step, char *line, int y)
{
	int			i;

	if (line && ft_strlen(line) == (step->m_size_x + X_CONST) &&
	ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2]) &&
	line[3] == ' ' && ft_atoi(line) == y)
	{
		i = X_CONST;
		while (line[i])
		{
			if (!ft_strchr(".XO", line[i]))
			{
printf("check_map_line | proble %s\n", &line[i]);
				error(step, line);
			}
			i++;
		}
		return ;
	}

printf("check_map_line | to much problems\n");
	error(step, line);
}

void			fill_map(t_flr *step)
{
	char		*line;
	int			i;


	i = 0;
	line = NULL;
	if (!step->map)
		if (!(step->map = ft_memalloc(sizeof(char*) * step->m_size_y)))
			error(step, NULL);
	while (i < step->p_size_y && get_next_line(0, &line))
	{
		check_map_line(step, line, i);
		step->map[i] = line + X_CONST;
		i++;
	}
	if (i != step->m_size_y)
	{
printf("fill_map/ i != step->m_size_y\n");
printf("fill_map/ %i != %i\n", i, step->m_size_y);
		error(step, NULL);
	}
}