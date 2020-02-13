#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // don't forget delite later
# include "libft.h"

# define RED			"\033[1;31m"
# define RESET			"\033[0m"

# define INF		1000000000
# define MY_HEAT	127
# define DEFAULT	126
# define P1_CHAR	'O'
# define P2_CHAR	'X'
# define X_CONST	4

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
* SET HEAT
*/
// void		init_heat_map(t_map *map);

/*
* T_FLR
*/
void		free_t_flr(t_flr *step);

/*
* MAP MANIPULATIONS
*/
void		fill_map(t_flr *step);

/*
* PIECE MANIPULATIONS
*/

/*
* PARSING
*/
void		get_vm_return(t_map *map, t_piece *p);

#endif