/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:33:30 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 15:33:31 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_y, int new_x)
{
	char	next;

	next = game->map[new_y][new_x];
	if (next == '1')
	{
		return ;
	}
	if (next == 'C')
	{
		game->collectibles--;
	}
	if ((next == 'E' && game->collectibles == 0) || next == 'M')
		clear_and_exit(game);
	game->map[game->player_y][game->player_x] = game->player_on;
	if (game->player_on == 'C')
		game->map[game->player_y][game->player_x] = '0';
	game->player_on = next;
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	put_image(game);
	put_steps(game);
}

void	go_up(t_game *game)
{
	move_player(game, game->player_y - 1, game->player_x);
}

void	go_down(t_game *game)
{
	move_player(game, game->player_y + 1, game->player_x);
}

void	go_left(t_game *game)
{
	move_player(game, game->player_y, game->player_x - 1);
}

void	go_right(t_game *game)
{
	move_player(game, game->player_y, game->player_x + 1);
}
