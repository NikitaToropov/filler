/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:34:49 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/16 17:19:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#define RESET			"\033[0m"
#define RED				"\033[1;31m"
#define PINK			"\033[1;35m"
#define BLUE			"\033[1;34m"
#define CYAN			"\033[1;36m"

static void			print_color_char(char c, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, &c, 1);
	write(1, RESET, ft_strlen(RESET));
}

static void			take_correct_collor(char c)
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

static void			print_map(void)
{
	char			*line;
	int				i;
	int				j;

	line = NULL;
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
	if (line)
		free(line);
}

static void			finish_line(char *line)
{
	if (!ft_strncmp(line, "== O fin:", 8))
	{
		write(1, "\n", 1);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
		get_next_line(0, &line);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	free(line);
}

int					main(void)
{
	char			*line;

	while (get_next_line(0, &line))
	{
		if (line && !ft_strncmp(line, "Plateau", 6))
		{
			free(line);
			print_map();
			usleep(100000);
		}
		else
			finish_line(line);
	}
	return (0);
}
