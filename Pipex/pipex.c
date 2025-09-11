/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:25:31 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/04 13:25:15 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process2(char **back, char **argv, int *fd, char **env)
{
	char	**cmd;
	int		ffd;

	cmd = ft_split(argv[3], ' ');
	if (!cmd)
	{
		free_split(back);
		return ;
	}
	ffd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (ffd == -1)
		free_errors(back, cmd);
	if (dup2(ffd, STDOUT_FILENO) == -1)
		free_errors(back, cmd);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		free_errors(back, cmd);
	close(fd[1]);
	close(ffd);
	poxos(cmd, env, back);
}

void	child_process(char *argv[], char *env[], int *fd, int flag)
{
	int		ffd;
	char	**back;
	char	**cmd;

	back = find_path(env);
	if (flag == 1)
	{
		cmd = ft_split(argv[2], ' ');
		if (!cmd)
		{
			free_split(back);
			return ;
		}
		ffd = open(argv[1], O_RDONLY);
		if (ffd == -1)
			free_errors(back, cmd);
		if (dup2(ffd, STDIN_FILENO) == -1)
			free_errors(back, cmd);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			free_errors(back, cmd);
		close(fd[0]);
		close(ffd);
		poxos(cmd, env, back);
	}
	child_process2(back, argv, fd, env);
}

int	main(int argc, char *argv[], char *env[])
{
	t_main	var;

	if (argc == 5)
	{
		if (pipe(var.fd) == -1)
			error("pipe", EXIT_FAILURE);
		var.pid1 = fork();
		if (var.pid1 == -1)
			error("fork failed", EXIT_FAILURE);
		if (var.pid1 == 0)
			child_process(argv, env, var.fd, 1);
		var.pid2 = fork();
		if (var.pid2 == -1)
			error("fork failed", EXIT_FAILURE);
		if (var.pid2 == 0)
			child_process(argv, env, var.fd, 0);
		close(var.fd[0]);
		close(var.fd[1]);
		waitpid(var.pid1, &var.status1, 0);
		waitpid(var.pid2, &var.status2, 0);
		exit(WEXITSTATUS(var.status2));
	}
	else
		error("argument count error", EXIT_FAILURE);
}
