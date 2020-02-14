#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // don't forget delite later
# include "libft.h"

# define RED			"\033[1;31m"
# define RESET			"\033[0m"

# define INF			1000000000
# define MY_HEAT		127
# define ENEMYS_HEAT	1
# define DEFAULT		126
# define P1_CHAR		'O'
# define P2_CHAR		'X'
# define X_CONST		4

typedef struct		s_flr
{
	char			**map;
	int				m_size_x;
	int				m_size_y;
	char			me;
	char			enemy;

	char			**piece;
	int				p_size_x;
	int				p_size_y;

	int				best_summ;
	int				best_x;
	int				best_y;
}					t_flr;


void		error(t_flr *step, char *line);

/*
* SOLVING
*/
void		find_best_heat_solution(t_flr *step);

/*
* SET HEAT
*/
void		fill_heat_map(t_flr *step);

/*
* T_FLR
*/
void		free_t_flr(t_flr *step);

/*
* MAP MANIPULATIONS
*/
void		free_lines_in_map(char **map, int size_y);
void		fill_map(t_flr *step);
void		print_map(t_flr *step);

/*
* PIECE MANIPULATIONS
*/
void		free_piece(t_flr *step);
void		fill_map_size(t_flr *step, char *line);
void		fill_piece(t_flr *step);
void		print_piece(t_flr *step);



/*
* PARSING
*/
void		get_vm_return(t_flr *step);

#endif