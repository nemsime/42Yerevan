/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:18:55 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 16:45:52 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "unistd.h"
# include <fcntl.h>
# define IMAGE mlx_put_image_to_window

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	char	**map;
	size_t	width;
	size_t	height;
	int		exit_count;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*imgplayer[5];
	void	*imgenemy[3];
	void	*img_exit;
	void	*img_collectible;
	void	*img_enemy;
	int		player_on;
	int		enemy_frame;
	int		enemy_timer;
}			t_game;

typedef struct s_validation
{
	int		p_count;
	int		e_count;
	char	*next_line;
}			t_validation;

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC 65307
# define UP 65362
# define RIGHT 65363
# define LEFT 65361
# define DOWN 65364

void		map_validation(int argc, char **argv, t_game *game);
void		end_error(int fd, char *str);
void		map_load(char **argv, t_game *game);
void		free_game(t_game *game);
void		free_tmp_map(char **tmp);
void		init_game(t_game *game);
void		create_window(t_game *game);
void		create_image(t_game *game);
int			clear_and_exit(t_game *game);
int			move_esc(int keycode, t_game *game);
void		put_image(t_game *game);
void		go_up(t_game *game);
void		go_down(t_game *game);
void		go_left(t_game *game);
void		go_right(t_game *game);
void		put_steps(t_game *game);
int			validate_line_content(char *line, t_game *game, t_validation *v);

#endif
