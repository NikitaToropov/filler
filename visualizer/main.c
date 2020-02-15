#include "libft.h"
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

# define X_CONST		4
# define RESET			"\033[0m"
# define RED			"\033[1;31m"
# define PINK			"\033[1;35m"
# define BLUE			"\033[1;34m"
# define CYAN			"\033[1;36m"

void		print_color_char(char c, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, &c, 1);
	write(1, RESET, ft_strlen(RESET));
}

void		take_correct_collor(char c)
{
	if (c == 'O')
		print_color_char(c, RED);
	else if (c == 'o')
		print_color_char(c, PINK);
	else if (c == 'X')
		print_color_char(c, BLUE);
	else if (c == 'x')
		print_color_char(c, CYAN);
	else
		write(1, &c, 1);
}

int			main(void)
{
	char	*line;
	int		i;
	int		j;

	while(get_next_line(0, &line))
	{
		if (line && !ft_strncmp(line, "Plateau", 6))
		{
			free(line);
			get_next_line(0, &line);
			system("clear");
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
			i = 0;
			while (get_next_line(0, &line) && line[3] == ' ' &&
			ft_atoi(line) == i)
			{
				j = 0;
				while (line[j])
					take_correct_collor(line[j++]);
				free(line);
				write(1, "\n", 1);
				i++;
			}
		}
		usleep(10000);
		if (!ft_strncmp(line, "== O fin:", 8))
		{
			write(1, "\n",1);
			write(1, line, ft_strlen(line));
			write(1, "\n",1);
			free(line);
			get_next_line(0, &line);
			write(1, line, ft_strlen(line));
			write(1, "\n",1);
		}
		free(line);
	}
	return (0);
}