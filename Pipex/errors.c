/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:50:35 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/04 13:25:20 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg, int k)
{
	if (errno == 0)
		errno = 13;
	perror(msg);
	exit(k);
}

void	free_errors(char **back, char **cmd)
{
	free_split(back);
	free_split(cmd);
	error("err", EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	access_ut(t_var var, char **cmd, char **env)
{
	free(var.tmp);
	execve(var.str, cmd, env);
}
