/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:38:52 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 17:15:26 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_border_line(char *line, t_game *game, char *next_line)
{
	size_t	i;

	i = 0;
	while (i < game->width)
	{
		if (line[i] != '1')
		{
			free(line);
			if (next_line)
				free(next_line);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_middle_chars(char *line, t_game *game, t_validation *v)
{
	size_t	i;

	i = 1;
	while (i < game->width - 1)
	{
		if (line[i] == 'P')
		{
			v->p_count++;
			game->player_x = i;
			game->player_y = game->height - 1;
		}
		else if (line[i] == 'E')
		{
			v->e_count++;
			game->exit_x = i;
			game->exit_y = game->height - 1;
		}
		else if (line[i] == 'C')
			game->collectibles++;
		else if (line[i] != '0' && line[i] != '1')
			return (free(line), 0);
		i++;
	}
	return (1);
}

int	validate_line_content(char *line, t_game *game, t_validation *v)
{
	if (game->height == 1 || v->next_line == NULL)
	{
		if (!validate_border_line(line, game, v->next_line))
			return (0);
	}
	else if (line[0] != '1' || line[game->width - 1] != '1')
	{
		free(line);
		free(v->next_line);
		return (0);
	}
	if (game->height > 1 && v->next_line != NULL)
	{
		if (!validate_middle_chars(line, game, v))
		{
			free(v->next_line);
			return (0);
		}
	}
	return (1);
}
