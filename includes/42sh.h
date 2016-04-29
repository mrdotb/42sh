/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/04/29 19:06:00 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S42_SH_H
# define S42_SH_H

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syslimits.h>

# define PROMPT "$> "

typedef struct		s_binary
{
	char			*name;
	char			*path;
	struct s_binary	*next;
}					t_binary;

void	router(char *line);
void	bc_cd(char **path);
void	bc_exit(char **path);
void	bc_clear(char **path);
void	bc_pwd(char **path);
void	bc_env(char **path);
void	bc_getenv(char **path);
void	bc_setenv(char **path);
void	bc_unsetenv(char **path);

void	bc_error(char *error_msg);
char	**cpy_env(char **environ, int add, int del);
t_binary	*get_binary(char *paths);


#endif
