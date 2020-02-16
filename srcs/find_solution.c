/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:34:08 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/16 18:00:02 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				print_result(t_flr *step)
{
	ft_putnbr(step->best_y);
	write(1, " ", 1);
	ft_putnbr(step->best_x);
	write(1, "\n", 1);
}

static int			check_position_in_piece(t_flr *step, int y_m, int x_m,
					int *summ)
{
	int				y_p;
	int				x_p;
	int				common;

	y_p = 0;
	common = 0;
	while (y_p < step->p_size_y)
	{
		x_p = 0;
		while (x_p < step->p_size_x)
		{
			if (step->piece[y_p][x_p] == '*' &&
			step->map[y_m + y_p][x_m + x_p] == ENEMYS_HEAT)
				return (0);
			else if (step->piece[y_p][x_p] == '*' &&
			step->map[y_m + y_p][x_m + x_p] == MY_HEAT)
				common++;
			else
				*summ += (int)step->map[y_m + y_p][x_m + x_p];
			x_p++;
		}
		y_p++;
	}
	return (common);
}

static void			check_position_in_map(t_flr *step, int y_m, int x_m)
{
	int				summ;
	int				common;

	if ((y_m + step->p_size_y) <= step->m_size_y &&
	(x_m + step->p_size_x) <= step->m_size_x)
	{
		summ = 0;
		common = check_position_in_piece(step, y_m, x_m, &summ);
		if (common == 1 && summ <= step->best_summ)
		{
			step->best_summ = summ;
			step->best_x = x_m;
			step->best_y = y_m;
		}
	}
}

void				find_best_heat_solution(t_flr *step)
{
	int				y;
	int				x;

	y = 0;
	while (y < step->m_size_y)
	{
		x = 0;
		while (x < step->m_size_x)
		{
			check_position_in_map(step, y, x);
			x++;
		}
		y++;
	}
}
