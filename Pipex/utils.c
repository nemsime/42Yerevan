/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:28:10 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/04 13:25:05 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char *env[])
{
	int		i;
	char	**paths;
	char	*str;

	paths = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			str = env[i] + 5;
			paths = ft_split((const char *)str, ':');
		}
		i++;
	}
	return (paths);
}

void	exit_command(char **path, char *str, char **cmd)
{
	if (path)
		free_split(path);
	if (cmd)
	{
		str = ft_strdup(cmd[0]);
		free_split(cmd);
		free(str);
		error(NULL, 127);
	}
	else
		perror("error");
	free_split(cmd);
	exit(127);
}

int	exit_str(char **path, char **tmp, char **str)
{
	if (path)
		free_split(path);
	if (*tmp)
	{
		free(*tmp);
		tmp = NULL;
	}
	if (*str)
	{
		free(*str);
		str = NULL;
	}
	if (!path)
		return (0);
	exit(1);
}

void	utils_poxos(char **tmp, char ***path, char **str, char ***cmd)
{
	if (!(*tmp))
		exit(1);
	if (!(*cmd) || !(*cmd)[0])
	{
		free((*tmp));
		exit_command((*path), (*str), (*cmd));
	}
	if ((*cmd)[0][0] != '/')
		(*str) = ft_strjoin((*tmp), (*cmd)[0]);
	else
		(*str) = ft_strjoin((*tmp), ft_strrchr((*cmd)[0], '/') + 1);
	if (!(*str))
		exit_str((*path), &(*tmp), NULL);
}

void	poxos(char **cmd, char *env[], char **path)
{
	t_var	var;

	var.i = -1;
	var.tmp = NULL;
	var.str = NULL;
	if (cmd && cmd[0] && (cmd[0][0] == '/' || !strncmp("./", cmd[0], 2)))
	{
		if (access(cmd[0], X_OK) == 0)
			execve(cmd[0], cmd, env);
	}
	else
	{
		if (!path || !*path)
			exit_command(path, var.str, cmd);
		while (path[++var.i])
		{
			var.tmp = ft_strjoin(path[var.i], "/");
			utils_poxos(&var.tmp, &path, &var.str, &cmd);
			if (access(var.str, X_OK) == 0)
				access_ut(var, cmd, env);
			if (!exit_str(NULL, &var.tmp, &var.str))
				continue ;
		}
		exit_command(path, var.str, cmd);
	}
}
