/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:00:49 by jraty             #+#    #+#             */
/*   Updated: 2020/08/05 14:51:34 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "/Users/jraty/testmygnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{	
	int		fd, fd2, fd3;
	char	*line;
	int		n = 0;
	static int i = 0;

	if (argc == 2 && ft_strcmp(argv[1], "stdin") == 0)
	{
		fd = 0;
		while (get_next_line(fd, &line) == 1)
		{
			printf("--------------------------------------------------------------\n");
			printf("\033[32mfd[%d] |%s|\033[0m\n", fd, line);
			free(line);
			i++;
		}
	}
	else if (argc == 2 && ft_strcmp(argv[1], "stdin") != 0)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("--------------------------------------------------------------\n");
			printf("\033[32mfd[%d] |%s|\033[0m\n", fd, line);
			free(line);
			i++;
		}
		close(fd);
		if (fd == -1)
			write(2, "error closing file1\n", 20);
	}
	else if (argc == 4)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		if (fd == -1 || fd2 == -1 || fd3 == -1)
		{
			write(2, "error opening file\n", 19);
			return (0);
		}
		while (get_next_line(fd, &line) == 1 && n < 3)
		{
			printf("--------------------------------------------------------------\n");
			printf("\033[32mfd[%d] |%s|\033[0m\n", fd, line);
			free(line);
			i++;
			n++;
		}
		free(line);
		n = 0;
		while (get_next_line(fd2, &line) == 1 && n < 3)
		{
			printf("--------------------------------------------------------------\n");
			printf("\033[32mfd[%d] |%s|\033[0m\n", fd2, line);
			free(line);
			i++;
			n++;
		}
		free(line);
		n = 0;
		while (get_next_line(fd3, &line) == 1 && n < 3)
		{
			printf("--------------------------------------------------------------\n");
			printf("\033[32mfd[%d] |%s|\033[0m\n", fd3, line);
			free(line);
			i++;
			n++;
		}
		close(fd);
		if (fd == -1)
			write(2, "error closing file1\n", 20);
		close(fd2);
		if (fd2 == -1)
			write(2, "error closing file2\n", 20);
		close(fd3);
		if (fd3 == -1)
			write(2, "error closing file3\n", 20);
	}
	else
	{
		write(2, "wrong number of arguments\n", 26);
		return (0);
	}
	printf("\033[01;36mPROGRAM FINISHED with BUFF_SIZE %d\033[0m\n", BUFF_SIZE);
	printf("\033[36m> > > > > > > > > > > > free(line) done (%d) times!\033[0m\n", i);
// TEST for LEAKS
//	while (1) ;
	return (0);
}
