// #include "libft.h"
#include <stdlib.h>
#include <unistd.h>

# define X_CONST		4
# define RESET			"\033[0m"
# define RED			"\033[1;31m"
# define PINK			"\033[1;39m"
# define BLUE			"\033[1;35m"
# define ANOTHER		"\033[34m"

void		print_color_char(char c, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, &c, 1);
	write(1, RESET, ft_strlen(RESET));
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
			while (get_next_line(0, &line) && ft_isdigit(line[0]) &&
			ft_isdigit(line[1]) && ft_isdigit(line[2]) && line[3] == ' ')
			{
				j = 0;
				while (line[j])
				{
					if (line[j] == 'O')
						print_color_char(line[j], RED);
					else if (line[j] == 'o')
						print_color_char(line[j], PINK);
					else if (line[j] == 'X')
						print_color_char(line[j], BLUE);
					else if (line[j] == 'x')
						print_color_char(line[j], ANOTHER);
					else
						write(1, &line[j], 1);
					j++;
				}
				free(line);
				write(1, "\n", 1);
				i++;
			}
		}
		// if (get_next_line(0, line) && ft_strncmp(line, "== O fin:", 8))
		// {
		// 	write(1, line, ft_strlen(line));
		// 	write(1, "\n", 1);
		// 	free(line);
		// 	get_next_line(0, line);
		// 	write(1, line, ft_strlen(line));
		// 	write(1, "\n", 1);
			
		// }
		usleep(100000);
		free(line);
	}
	return (0);
}