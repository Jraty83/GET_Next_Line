/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:00:49 by jraty             #+#    #+#             */
/*   Updated: 2020/08/04 14:36:57 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "/Users/jraty/testmygnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{	
	int		fd;
	char	*line;
	static int i = 0;

	if (argc < 2)
		fd = 0;
//		write(2, "nothing to read\n", 16);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "error opening file\n", 19);
			close(fd);
			if (fd == -1)
				write(2, "error closing file\n", 19);
			return (-1);
		}
	}
	while (get_next_line(fd, &line) == 1)
	{
		printf("--------------------------------------------------------------\n");
		printf("\033[32mfd[%d] |%s|\033[0m\n", fd, line);
		free(line);
		i++;
	}
	close(fd);
	if (fd == -1)
		write(2, "error closing file\n", 19);
	printf("\033[01;36mPROGRAM FINISHED with BUFF_SIZE %d\033[0m\n", BUFF_SIZE);
	printf("\033[36m> > > > > > > > > > > > free(line) done (%d) times!\033[0m\n", i);
/* TEST for LEAKS
	while (1)
		;
*/
	return (0);
}
