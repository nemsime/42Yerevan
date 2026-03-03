#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_parse_state
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;

}					t_parse_state;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
}					t_map;

typedef struct s_assets
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;

	int				floor_color;
	int				ceiling_color;
}					t_assets;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
}					t_player;

typedef struct s_game
{
	t_map			map;
	t_assets		assets;
	t_player		player;
	t_parse_state	state;

	void			*mlx;
	void			*win;
	void			*img;

}					t_game;

void				validation_stage(int argc, char **argv, t_game *game);
void				end_error(int fd, char *str);
void				free_split(char ***arr);
void	free_game_content(t_game *game);

#endif