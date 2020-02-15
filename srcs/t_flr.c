/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:32:49 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/15 19:58:23 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

	if (map)
	{
		i = 0;
		while (i < size_y)
		{
			if (map[i])
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
