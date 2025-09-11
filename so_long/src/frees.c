/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:11:44 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 13:50:54 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->map)
	{
		while (i < game->height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	free_tmp_map(char **tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i] != NULL)
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
}
