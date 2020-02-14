#include "filler.h"

void		check_position(t_flr *step, int y_m, int x_m)
{
	int		summ;
	int		y_p;
	int		x_p;
	int		common;

	summ = 0;
	if ((y_m + step->p_size_y) <= step->m_size_y &&
	(x_m + step->p_size_x) <= step->m_size_x)
	{
		y_p = 0;
		common = 0;
		while (y_p < step->p_size_y)
		{
			x_p = 0;
			while (x_p < step->p_size_x)
			{
				if (step->piece[y_p][x_p] == '*' &&
				step->map[y_m + y_p][x_m + x_p] == ENEMYS_HEAT)
					return ;
				else if (step->piece[y_p][x_p] == '*' &&
				step->map[y_m + y_p][x_m + x_p] == MY_HEAT)
					common++;
				x_p++;
			}
			y_p++;
		}
	}
}

void		find_best_heat_solution(t_flr *step)
{
	int			y;
	int			x;

	while (y < step->m_size_y)
	{
		x = 0;
		while (x < step->m_size_x)
		{
			check_position(step, y, x);
			x++;
		}
		y++;
	}
}