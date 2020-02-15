/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:32:38 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/15 19:55:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			fill_piece_size(t_flr *step)
{
	char			*line;
	char			*y_str;
	char			*x_str;
	int				y;
	int				x;

	y = 0;
	x = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0 || ft_strncmp(line, "Piece", 4))
		error(step, line);
	y_str = ft_strchr(line, ' ');
	if (!y_str || !(x_str = ft_strchr(y_str + 1, ' ')) ||
	ft_strchr(x_str + 1, ' '))
		error(step, line);
	y = ft_atoi(y_str);
	x = ft_atoi(x_str);
	if (y < 1 || x < 1 || (step->p_size_y > 0 && y != step->m_size_y) ||
	(step->p_size_x > 0 && x != step->m_size_x))
		error(step, line);
	step->p_size_y = y;
	step->p_size_x = x;
	if (step->p_size_y > step->m_size_y || step->p_size_x > step->m_size_x)
		error(step, line);
	free(line);
}

static void			check_piece_line(t_flr *step, char *line)
{
	int				i;

	i = 0;
	if (line && ft_strlen(line) == (size_t)step->p_size_x)
	{
		while (line[i])
		{
			if (!ft_strchr(".*", line[i]))
				error(step, line);
			i++;
		}
	}
	else
		error(step, line);
}

void				fill_piece(t_flr *step)
{
	char			*line;
	int				i;

	fill_piece_size(step);
	if (!step->piece)
		if (!(step->piece = ft_memalloc(sizeof(char*) * step->p_size_y)))
			error(step, NULL);
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
		error(step, NULL);
	}
}
