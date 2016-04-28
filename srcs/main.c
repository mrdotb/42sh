/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:14:35 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/28 16:23:00 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//comd pwd a refaire aussi bonus

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**args;
	int		ret;
	pid_t	fat;

	fd = 0;
	ret = 1;
	if (ac != 1 && av[0])
		return (0);
	while (write(1, "$> ", 3) && (ret = ft_gnl(0, &line)) != 0)
	{
		if (!ft_strcmp("exit", line))
			exit (-1);
		fat = fork();
		if (fat)
			wait(&fat);
		else
		{
			if (line[0] == 'l' && line[1] == 's')
			{
				args = ft_strsplit(line, ' ');
				execve("/bin/ls", args, NULL);
			}
			else if (line[0] == 'c' && line[1] == 'd')
			{
				args = ft_strsplit(line, ' ');
				chdir(args[1]);
				printf("%s\n", args[1]);
			}
		}
	}
	close(fd);
	return (0);
}
