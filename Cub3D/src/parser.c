#include "../include/cub3d.h"

int	is_empty(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	starts_with(char *line, const char *element)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (element[j] && line[i + j])
	{
		if (line[i + j] != element[j])
			return (0);
		j++;
	}
	if (element[j] == '\0')
		return (1);
	return (0);
}

void	trim_right(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len
			- 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
}

char	*space_move(char **line, char *element)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	*line += ft_strlen(element);
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (**line == '\0' || **line == '\n')
		return (NULL);
	return (*line);
}

void	assets_input(t_game **game, char *element, char *texture, int color)
{
	if (starts_with(element, "NO "))
		(*game)->assets.no = ft_strdup(texture);
	if (starts_with(element, "SO "))
		(*game)->assets.so = ft_strdup(texture);
	if (starts_with(element, "WE "))
		(*game)->assets.we = ft_strdup(texture);
	if (starts_with(element, "EA "))
		(*game)->assets.ea = ft_strdup(texture);
	if (starts_with(element, "F "))
		(*game)->assets.floor_color = color;
	if (starts_with(element, "C "))
		(*game)->assets.ceiling_color = color;
}

void	set_flag(t_game **game, char *element)
{
	if (starts_with(element, "NO "))
		(*game)->assets.state.no++;
	if (starts_with(element, "SO "))
		(*game)->assets.state.so++;
	if (starts_with(element, "WE "))
		(*game)->assets.state.we++;
	if (starts_with(element, "EA "))
		(*game)->assets.state.ea++;
	if (starts_with(element, "F "))
		(*game)->assets.state.f++;
	if (starts_with(element, "C "))
		(*game)->assets.state.c++;
}

int	check_flag(t_game *game, char flag)
{
	if (flag == 'D' && (game->assets.state.we > 1 || game->assets.state.ea > 1
			|| game->assets.state.so > 1 || game->assets.state.no > 1 || game->assets.state.c > 1
			|| game->assets.state.f > 1))
		return (1);
	else if (flag == 'Z' && (game->assets.state.we == 0 || game->assets.state.ea == 0
			|| game->assets.state.so == 0 || game->assets.state.no == 0 || game->assets.state.c == 0
			|| game->assets.state.f == 0))
		return (1);
	else
		return (0);
}

int	parse_texture(char *line, char *element, t_game *game)
{
	int	len;
	int	fd;

	if (!space_move(&line, element))
		return (0);
	trim_right(line);
	len = ft_strlen(line);
	if (len < 4 || ft_strncmp(line + len - 4, ".xpm", 4) != 0)
		return (0);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	set_flag(&game, element);
	if (check_flag(game, 'D'))
		return (0);
	assets_input(&game, element, line, 0);
	return (1);
}

int	get_rgb_value(char *rgb)
{
	char	*clean;
	int		j;
	int		value;

	j = 0;
	clean = ft_strtrim(rgb, " \t\n\r");
	if (!clean || clean[0] == '\0')
		return (-1);
	while (clean[j])
	{
		if (!ft_isdigit(clean[j]))
			return (free(clean), -1);
		j++;
	}
	value = ft_atoi(clean);
	if (value < 0 || value > 255)
		return (free(clean), -1);
	return (free(clean), value);
}

int	parse_color(char *line, char *element, t_game *game)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	int		color;

	if (!space_move(&line, element))
		return (0);
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (free_split(&rgb), 0);
	r = get_rgb_value(rgb[0]);
	g = get_rgb_value(rgb[1]);
	b = get_rgb_value(rgb[2]);
	free_split(&rgb);
	if (r < 0 || g < 0 || b < 0)
		return (0);
	color = (r << 16) | (g << 8) | b;
	set_flag(&game, element);
	if (check_flag(game, 'D'))
		return (0);
	assets_input(&game, element, line, color);
	return (1);
}

int is_first_wall(char *line,t_map *map)
{
	char *tmp = ft_strtrim(line, " \t\n\r");
	char *ptr = tmp;
	while(*tmp && (*tmp == ' ' || *tmp == '1'))
		tmp++;
	if(*tmp == '\0')
	{
		free(ptr);
		return 1;
	}
	free(ptr);
	return 0;
} 

int	process_elements(char *line, t_game *game,int fd)
{
	if (is_empty(line))
		return (1);
	if (starts_with(line, "NO "))
		return (parse_texture(line, "NO ", game));
	if (starts_with(line, "SO "))
		return (parse_texture(line, "SO ", game));
	if (starts_with(line, "WE "))
		return (parse_texture(line, "WE ", game));
	if (starts_with(line, "EA "))
		return (parse_texture(line, "EA ", game));
	if (starts_with(line, "F "))
		return (parse_color(line, "F ", game));
	if (starts_with(line, "C "))
		return (parse_color(line, "C ", game));
	return (0);
}

int add_map_line(t_map *map, char *line)
{
    t_map_node *new_node;
	t_map_node *tmp;
	int len;

	new_node = malloc(sizeof(t_map_node));
    if (!new_node)
        return 0;
    new_node->line = ft_strdup(line);
    if (!new_node->line)
        return (free(new_node),0);
    new_node->next = NULL;
    if (!map->head)
        map->head = new_node;
    else
    {
        tmp = map->head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    len = ft_strlen(line);
    if (len > map->width)
        map->width = len;
    map->height++;
    return 1;
}

int map_parsing(int fd,char *top_line,t_map *map)
{
    char *cur_line;
	int i;

	if (!add_map_line(map, top_line))
		return (0);
    cur_line = get_next_line(fd);
    while (cur_line)
    {
        if (is_empty(cur_line))
            return (free(cur_line),0);
		i = 0;
        while (cur_line[i])
        {
            if (cur_line[i] != ' ' && cur_line[i] != '0' && cur_line[i] != '1' &&
                cur_line[i] != 'N' && cur_line[i] != 'S' &&
                cur_line[i] != 'E' && cur_line[i] != 'W')
                return (free(cur_line),0);
			i++;
        }
        if (!add_map_line(map, cur_line))
            return (free(cur_line),0);
        free(cur_line);
        cur_line = get_next_line(fd);
    }
    return (1); 
}

int	validate_file(int fd, t_game *game)
{
	char	*line;
	line = get_next_line(fd);
	if (!line || line[0] == '\n' || line[0] == '\0')
	{
		if (line)
			free(line);
		return (0);
	}
	while (line)
	{
		if(is_first_wall(line,&game->map))
			break;
		if (!process_elements(line, game, fd))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	if (check_flag(game, 'Z') || (line[0] == '\0' || line[0] == '\n'))
		return (free(line),0);
	if (!map_parsing(fd, line, &game->map))
	{
		free_map(&game->map);
    	return (free(line), 0);
	}
	return (1);
}

void	validation_stage(int argc, char **argv, t_game *game)
{
	size_t	len;
	int		fd;

	if (argc != 2)
		end_error(0, "ERROR: usage: ./cub3D <*.cub>\n");
	len = ft_strlen(argv[1]);
	if (len < 4 || (ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0))
		end_error(0, "ERROR: map must be .cub file\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		end_error(0, "ERROR: open failed\n");
	ft_memset(game, 0, sizeof(t_game));
	if (!validate_file(fd, game))
	{
		free_game_content(game);
		get_next_line(-1);
		end_error(fd, "ERROR: elements are not valid\n");
	}
	close(fd);
}
