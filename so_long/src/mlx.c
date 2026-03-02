/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:58:54 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 15:30:25 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_steps(t_game *game)
{
	char	*step_str;
	char	*msg;

	step_str = ft_itoa(game->moves);
	if (!step_str)
		return ;
	msg = ft_strjoin("Moves: ", step_str);
	free(step_str);
	if (!msg)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, msg);
	free(msg);
}

int	move_esc(int keycode, t_game *game)
{
	if (keycode == W_KEY || keycode == UP)
		go_up(game);
	else if (keycode == S_KEY || keycode == DOWN)
		go_down(game);
	else if (keycode == D_KEY || keycode == RIGHT)
		go_right(game);
	else if (keycode == A_KEY || keycode == LEFT)
		go_left(game);
	else if (keycode == ESC)
		clear_and_exit(game);
	return (0);
}

int	clear_and_exit(t_game *game)
{
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	exit(0);
	return (0);
}

void	put_image(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			IMAGE(game->mlx, game->win, game->img_floor, 32 * j, 32 * i);
			if ((game->map)[i][j] == '1')
				IMAGE(game->mlx, game->win, game->img_wall, 32 * j, 32 * i);
			else if ((game->map)[i][j] == 'P')
				IMAGE(game->mlx, game->win, game->img_player, 32 * j, 32 * i);
			else if ((game->map)[i][j] == 'E')
				IMAGE(game->mlx, game->win, game->img_exit, 32 * j, 32 * i);
			else if ((game->map)[i][j] == 'C')
				IMAGE(game->mlx, game->win, game->img_collectible, 32 * j, 32
					* i);
			else if ((game->map)[i][j] == 'M')
				IMAGE(game->mlx, game->win, game->img_enemy, 32 * j, 32 * i);
			j++;
		}
		i++;
	}
}

void	create_image(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./SO_LONG/PLAYER/PLAYER_STANDS.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./SO_LONG/COIN/COIN.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./SO_LONG/EXIT/EXIT.xpm",
			&w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./SO_LONG/FLOOR/grass.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./SO_LONG/WALL/hills.xpm", &w, &h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"./SO_LONG/ENEMY/ENEMY.xpm", &w, &h);
	if (!game->img_player || !game->img_collectible || !game->img_exit
		|| !game->img_floor || !game->img_wall || !game->img_enemy)
		clear_and_exit(game);
	put_image(game);
}
