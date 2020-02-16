/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_heat_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:32:58 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/16 18:10:10 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			set_default_heat(t_flr *step)
{
	char			*line;
	int				i;

	i = 0;
	while (i < step->m_size_y)
	{
		line = step->map[i];
		while (*line)
		{
			if (*line == step->me)
				*line = MY_HEAT;
			else if (*line == step->enemy)
				*line = 1;
			else
				*line = DEFAULT;
			line++;
		}
		i++;
	}
}

static int			set_heat_aroud_part_two(t_flr *step, int y, int x, char h)
{
	int				i;
	char			**map;

	i = 0;
	map = step->map;
	if ((x + 1) < step->m_size_x &&
	map[y][x + 1] != MY_HEAT && map[y][x + 1] > h && (i = 1))
		map[y][x + 1] = h;
	if ((y - 1) >= 0 && (x - 1) >= 0 &&
	map[y - 1][x - 1] != MY_HEAT && map[y - 1][x - 1] > h && (i = 1))
		map[y - 1][x - 1] = h;
	if ((y - 1) >= 0 &&
	map[y - 1][x] != MY_HEAT && map[y - 1][x] > h && (i = 1))
		map[y - 1][x] = h;
	if ((y - 1) >= 0 && (x + 1) < step->m_size_x &&
	map[y - 1][x + 1] != MY_HEAT && map[y - 1][x + 1] > h && (i = 1))
		map[y - 1][x + 1] = h;
	return (i);
}

static int			set_heat_aroud(t_flr *step, int y, int x, char h)
{
	int				i;
	char			**map;

	i = 0;
	map = step->map;
	if ((y + 1) < step->m_size_y && (x - 1) >= 0 &&
	map[y + 1][x - 1] != MY_HEAT && map[y + 1][x - 1] > h && (i = 1))
		map[y + 1][x - 1] = h;
	if ((y + 1) < step->m_size_y &&
	map[y + 1][x] != MY_HEAT && map[y + 1][x] > h && (i = 1))
		map[y + 1][x] = h;
	if ((y + 1) < step->m_size_y && (x + 1) < step->m_size_x &&
	map[y + 1][x + 1] != MY_HEAT && map[y + 1][x + 1] > h && (i = 1))
		map[y + 1][x + 1] = h;
	if ((x - 1) >= 0 &&
	map[y][x - 1] != MY_HEAT && map[y][x - 1] > h && (i = 1))
		map[y][x - 1] = h;
	i += set_heat_aroud_part_two(step, y, x, h);
	return (i);
}

static int			set_the_heat(t_flr *step, char heat)
{
	int				y;
	int				x;
	char			prev;
	char			marker;

	y = 0;
	marker = 0;
	prev = heat - 1;
	while (y < step->m_size_y)
	{
		x = 0;
		while (x < step->m_size_x)
		{
			if (step->map[y][x] == prev)
			{
				if (set_heat_aroud(step, y, x, heat))
					marker = 1;
			}
			x++;
		}
		y++;
	}
	return (marker);
}

void				fill_heat_map(t_flr *step)
{
	char			heat;

	set_default_heat(step);
	heat = 2;
	while (heat < MY_HEAT && set_the_heat(step, heat))
		heat++;
}
