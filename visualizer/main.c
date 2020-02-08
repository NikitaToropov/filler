// #include "libft.h"
#include <stdlib.h>
#include <unistd.h>

# define X_CONST		4

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
			// while (get_next_line(0, &line) && ft_atoi(line) == i)
			while (get_next_line(0, &line) && ft_isdigit(line[0]) &&
			ft_isdigit(line[1]) && ft_isdigit(line[2]) && line[3] == ' ')
			{
				j = 0;
				while (line[j])
				{
					write(1, &line[j], 1);
					j++;
				}
				free(line);
				write(1, "\n", 1);
				i++;
			}
		}
		usleep(10000);

		free(line);
	}
	// while (get_next_line(0, &line) && ft_atoi(line) == i)
	// {
	// 	j = X_CONST;
	// 	while (line[j])
	// 	{
	// 		write(1, &line[j], 1);
	// 		// if (line[j] == o)
	// 		// {
	// 		// 	write(1, "", );
	// 		// }
	// 		j++;
	// 	}
	// 	write(1, "\n", 1);
	// 	usleep(10000);
	// 	system("clear");
	// 	i++;
	// }
	return (0);
}