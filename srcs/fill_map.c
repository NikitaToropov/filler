/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:35:05 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/21 10:49:19 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				check_num_line(t_flr *step)
{
	char			*line;

	line = NULL;
	if (!get_next_line(0, &line) || ft_strlen(line) <= 4 ||
	ft_strncmp(line, "    ", 3) || !ft_allisdigit(line + 4))
		error(step, line);
	free(line);
}

void				fill_map_size(t_flr *step)
{
	char			*y_str;
	char			*x_str;
	char			*line;
	int				y;
	int				x;

	y = 0;
	x = 0;
	line = NULL;
	if (!get_next_line(0, &line) || ft_strncmp(line, "Plateau", 6))
		error(step, line);
	y_str = ft_strchr(line, ' ');
	if (!y_str || !(x_str = ft_strchr(y_str + 1, ' ')) ||
	ft_strchr(x_str + 1, ' '))
		error(step, line);
	x = ft_atoi(x_str);
	y = ft_atoi(y_str);
	if (y < 1 || x < 1 || (step->m_size_y > 0 && y != step->m_size_y) ||
	(step->m_size_x > 0 && x != step->m_size_x))
		error(step, line);
	step->m_size_y = y;
	step->m_size_x = x;
	free(line);
	check_num_line(step);
}

static void			check_map_line(t_flr *step, char *line, int y)
{
	int				i;

	if (line && ft_strlen(line) == (size_t)(step->m_size_x + X_CONST) &&
	ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2]) &&
	line[3] == ' ' && ft_atoi(line) == y)
	{
		i = X_CONST;
		while (line[i])
		{
			if (!ft_strchr(".XO", line[i]))
				error(step, line);
			i++;
		}
		return ;
	}
	error(step, line);
}

void				fill_map(t_flr *step)
{
	char			*line;
	int				i;

	if (!step->map)
		if (!(step->map = ft_memalloc(sizeof(char*) * step->m_size_y)))
			error(step, NULL);
	i = 0;
	line = NULL;
	while (i < step->m_size_y && get_next_line(0, &line))
	{
		check_map_line(step, line, i);
		step->map[i] = line + X_CONST;
		i++;
	}
	if (i != step->m_size_y)
		error(step, NULL);
}
