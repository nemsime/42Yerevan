/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:27:59 by mtumanya          #+#    #+#             */
/*   Updated: 2025/06/18 19:34:54 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h> 
# include <stdio.h> 
# include <stdlib.h> 
# include <string.h> 
# include <sys/types.h> 
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_main
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;
}			t_main;

typedef struct s_var
{
	char	*str;
	char	*tmp;
	int		i;
}			t_var;

void		free_errors(char **back, char **cmd);
void		free_split(char **str);
void		error(char *msg, int k);
void		poxos(char **argv, char *env[], char **path);
char		**find_path(char *env[]);
void		access_ut(t_var var, char **cmd, char **env);

#endif