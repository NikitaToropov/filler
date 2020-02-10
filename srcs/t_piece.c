#include "filler.h"

void		free_piece(t_piece *p)
{
	int		i;

	if (p->piece)
	{
		i = 0;
		while (i < p->size_y)
		{
			if (p->piece[i])
				free(p->piece[i]);
			i++;
		}
		free(p->piece);
		p->piece = NULL;
	}
}

void		init_t_piece(t_piece *p)
{
	p->piece = NULL;
	p->size_x = 0;
	p->size_y = 0;
}