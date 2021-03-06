/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:35:32 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/15 20:00:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			reset_t_flr(t_flr *step)
{
	free_piece(step);
	free_lines_in_map(step->map, step->m_size_y);
	step->piece = NULL;
	step->p_size_x = 0;
	step->p_size_y = 0;
	step->best_x = -1;
	step->best_y = -1;
	step->best_summ = INF;
}

void				error(t_flr *step, char *line)
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

static void			get_player(t_flr *step)
{
	char			*line;

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
		else if (ft_strstr(line, "p1"))
		{
			step->me = P1_CHAR;
			step->enemy = P2_CHAR;
		}
		else
			error(step, line);
		free(line);
	}
	else
		error(step, line);
}

static void			init_t_flr(t_flr *step)
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

int					main(void)
{
	t_flr			step;

	init_t_flr(&step);
	get_player(&step);
	while (1)
	{
		fill_map_size(&step);
		fill_map(&step);
		fill_piece(&step);
		fill_heat_map(&step);
		find_best_heat_solution(&step);
		if (step.best_x == -1 || step.best_x == -1)
		{
			write(1, "0 0\n", 4);
			free_t_flr(&step);
			return (0);
		}
		print_result(&step);
		reset_t_flr(&step);
	}
	free_t_flr(&step);
	return (0);
}
