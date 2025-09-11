/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:36:11 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 13:50:58 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_game *game, int p_x, int p_y)
{
	if (p_x < 0 || p_y < 0 || !map[p_y][p_x] || map[p_y][p_x] == '1'
		|| map[p_y][p_x] == 'M' || map[p_y][p_x] == 'X')
		return ;
	if (map[p_y][p_x] == 'E')
		game->exit_count = 1;
	map[p_y][p_x] = 'X';
	flood_fill(map, game, p_x + 1, p_y);
	flood_fill(map, game, p_x - 1, p_y);
	flood_fill(map, game, p_x, p_y + 1);
	flood_fill(map, game, p_x, p_y - 1);
}

int	valid_flood(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'E' || tmp[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	copy_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	char	**tmp_map;

	i = 0;
	line = get_next_line(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	tmp_map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map || !line || !tmp_map)
		return (free_game(game), free_tmp_map(tmp_map), 0);
	while (line != NULL)
	{
		game->map[i] = line;
		tmp_map[i] = ft_strdup(line);
		if (tmp_map[i] == NULL)
			return (free_tmp_map(tmp_map), 0);
		line = get_next_line(fd);
		i++;
	}
	tmp_map[i] = NULL;
	game->map[i] = NULL;
	flood_fill(tmp_map, game, game->player_x, game->player_y);
	if (!valid_flood(tmp_map))
		return (free_tmp_map(tmp_map), 0);
	return (free_tmp_map(tmp_map), 1);
}

void	map_load(char **argv, t_game *game)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		end_error(0, "ERROR: open failed\n");
	if (!copy_map(fd, game))
	{
		if (game->map || *game->map)
			free_game(game);
		end_error(fd, "ERROR: map copy issue or access to E or C\n");
	}
	close(fd);
}
