#include "../include/cub3d.h"

int is_empty(char *line)
{
    int i;

    if (!line)
        return (1);

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t'
            && line[i] != '\n' && line[i] != '\r')
            return (0);
        i++;
    }
    return (1);
}

int starts_with(char *line,const char *element)
{
    
    int i;
    int j;

    i = 0;
    j = 0;
    while (line[i] && (line[i] == ' ' || line[i] == '\t'))
            i++;
    while(element[j] && line[i+j])
    {
        if(line[i+j] != element[j])
            return (0);
        j++;
    }
    if(element[j] == '\0')
        return (1);
    return (0);
}

void trim_right(char *str)
{
    int len;

    if (!str)
        return;

    len = ft_strlen(str);

    while (len > 0 &&
        (str[len - 1] == ' ' ||
         str[len - 1] == '\t' ||
         str[len - 1] == '\n' ||
         str[len - 1] == '\r'))
    {
        str[len - 1] = '\0';
        len--;
    }
}
int space_move(char *line,int *i,char *element)
{
    while (line[*i] == ' ' || line[*i] == '\t')
        (*i)++;
    *i += ft_strlen(element);
    while (line[*i] == ' ' || line[*i] == '\t')
        (*i)++;
    if (line[*i] == '\0' || line[*i] == '\n')
        return (0);
    return *i;
}
void assets_input(t_game **game,char *path,char *line)
{
    if (starts_with(line, "NO "))
    {
        printf("%s",(*game)->assets.no = path);
        (*game)->assets.no = path;
    }

    if (starts_with(line, "SO "))
        (*game)->assets.so = path;

    if (starts_with(line, "WE "))
        (*game)->assets.we = path;

    if (starts_with(line, "EA "))
        (*game)->assets.ea = path;

    if (starts_with(line, "F "))
        (*game)->assets.we = path;
    
    if (starts_with(line, "C "))
        (*game)->assets.we = path;
}
int parse_texture(char *line,char *element,t_game ****game)
{
    int i = 0;
    if(!space_move(line,&i,element))
        return (0);
    char *path = &line[i];
    trim_right(path);
    int len = ft_strlen(path);
    if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
        return (0);
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return (0);
    close(fd);
    assets_input(**game,path,line);
    return (1);
}

int parse_color(char *line,char *element,t_game ****game)
{
    int i;
    char *clean;
    int count;
    int j;
    char **rgb;

    i = 0;
    if(!space_move(line,&i,element))
        return (0);
    rgb = ft_split(&line[i], ',');
    if (!rgb)
        return (0);
    count = 0;
    while (rgb[count]) 
        count++;
    if (count != 3)
        return (0);
    while(rgb[--count])
    {
        if(count < 0)
            break;
        clean = ft_strtrim(rgb[count], " \t\n\r");
        if (!clean || clean[0] == '\0')
            return (free_split(&rgb), 0);
        j = 0;
        while (clean[j])
        {
            if (!ft_isdigit(clean[j]))
                return (0);
            j++;
        }
        int value = ft_atoi(clean);
        if (value < 0 || value > 255)
            return (0);
        if(element[0] == 'F')
            (***game)->assets.ceiling_color = value;
        else
            (***game)->assets.floor_color = value;
    }
    return (1);
}


int process_line(char *line,t_game ***game)
{
    if (is_empty(line))
        return (1);

    if (starts_with(line, "NO "))
        return (parse_texture(line,"NO ",&game));

    if (starts_with(line, "SO "))
        return (parse_texture(line,"SO ",&game));

    if (starts_with(line, "WE "))
        return (parse_texture(line,"WE ",&game));

    if (starts_with(line, "EA "))
        return (parse_texture(line,"EA ",&game));

    if (starts_with(line, "F "))
        return (parse_color(line,"F ",&game));
    
    if (starts_with(line, "C "))
        return (parse_color(line,"C ",&game));


    return (1);
}

int validate_elements(int fd,t_game **game)
{
    char *line = get_next_line(fd);
    if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
		return (0);
	}
    while(line)
    {
        if(!process_line(line,&game))
            return (free(line),0); 
        free(line);
        line = get_next_line(fd);
    }
    return (1);
}

void validation_stage(int argc,char **argv,t_game *game)
{
    if(argc != 2)
        end_error(0,"ERROR: usage: ./cub3D <*.cub>\n");
    size_t len = ft_strlen(argv[1]);
    if (len < 4 || (ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0))
		end_error(0, "ERROR: map must be .cub file\n");
    int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		end_error(0, "ERROR: open failed\n");
	ft_memset(game, 0, sizeof(t_game));
	if (!validate_elements(fd, &game))
	{
		get_next_line(-1);
		end_error(fd, "ERROR: map is not valid\n");
	}
	close(fd);
}

