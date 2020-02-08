#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // don't forget delite later
# include "libft.h"

# define INF		1000000000
# define P1_ABC		"oO"
# define P2_ABC		"xX"
# define X_CONST	4

typedef struct		s_map
{
	char			**map;
	int				size_x;
	int				size_y;
	char			player;

	int				best_summ;
	int				best_x;
	char			*my_abc;
	char			*opp_abc;

	// int				map_size_x;
	// int				map_size_y;
	// char			*en;
	// int				pos_enemy_x;
	// int				pos_enemy_y;
	// int				my_pos_x;
	// int				my_pos_y;
	// int				first_x;
	// int				first_y;
	// char			*me;
	// void			*win;
	// void			*mlx;
	// void			*img;
	// int				bits_per_pixel;
	// int				size_line;
	// int				endian;
	// char			*ret;
}					t_map;

typedef struct		s_piece
{
	char			**piece;

	int				size_x;
	int				size_y;

	// int				nbr_contact;
	// int				contact;
	// int				final_x;
	// int				final_y;
	// int				size_x;
	// int				size_y;
	// int				real_size_x;
	// int				real_size_y;
	// int				start_x;
	// int				end_x;
	// int				start_y;
	// int				end_y;
}					t_piece;

#endif