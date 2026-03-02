/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:12:19 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 15:38:34 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_line_length(char *line, t_game *game, char *next_line)
{
	size_t	c_len;

	c_len = ft_strlen(line);
	if ((line[c_len - 1] == '\n' && c_len - 1 != game->width)
		|| (line[c_len - 1] != '\n' && c_len != game->width))
	{
		if (next_line)
			free(next_line);
		return (free(line), 0);
	}
	return (1);
}

static void	validate_counts(int fd, t_validation *v, t_game *game)
{
	if ((game->width < 3 || game->height < 5) && (game->width < 5
			|| game->height < 3))
		end_error(fd, "map should be at least 5x3 or 3x5\n");
	if (v->p_count != 1 || v->e_count != 1 || game->collectibles < 1)
	{
		if (v->p_count != 1)
			end_error(fd, "Map must have exactly 1 Player (P)\n");
		else if (v->e_count != 1)
			end_error(fd, "Map must have exactly 1 Exit (E)\n");
		else
			end_error(fd, "Map must have at least 1 Collectible (C)\n");
	}
}

int	validate_map(int fd, t_game *game, t_validation *v)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || line[0] == '\n' || line[0] == '\0')
	{
		if (line)
			free(line);
		return (0);
	}
	game->width = ft_strlen(line);
	if (line[game->width - 1] == '\n')
		game->width--;
	while (line)
	{
		game->height++;
		v->next_line = get_next_line(fd);
		if (!validate_line_length(line, game, v->next_line))
			return (0);
		if (!validate_line_content(line, game, v))
			return (0);
		free(line);
		line = v->next_line;
	}
	validate_counts(fd, v, game);
	return (1);
}

void	map_validation(int argc, char **argv, t_game *game)
{
	int				fd;
	size_t			len;
	t_validation	v;

	if (argc != 2)
		end_error(0, "ERROR: usage: ./so_long <?.ber>\n");
	len = ft_strlen(argv[1]);
	if (len < 4 || (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0))
		end_error(0, "ERROR: map must be .ber file\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		end_error(0, "ERROR: open failed\n");
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(&v, 0, sizeof(t_validation));
	if (!validate_map(fd, game, &v))
	{
		get_next_line(-1);
		end_error(fd, "ERROR: map is not valid\n");
	}
	close(fd);
}
