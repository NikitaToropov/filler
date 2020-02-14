#include "filler.h"

void		print_result(t_flr *step)
{
	ft_putnbr(step->best_y);
	write(1, " ", 1);
	ft_putnbr(step->best_x);
	write(1, "\n", 1);
}

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
				else
					summ += (int)step->map[y_m + y_p][x_m + x_p];
				x_p++;
			}
			y_p++;
		}
		if (common == 1 && summ < step->best_summ)
		{
			step->best_summ = summ;
			step->best_x = x_m;
			step->best_y = y_m;
		}
	}
}

void			find_best_heat_solution(t_flr *step)
{
	int			y;
	int			x;

	y = 0;
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