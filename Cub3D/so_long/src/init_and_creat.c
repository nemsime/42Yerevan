/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_creat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:33:50 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 15:41:41 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		end_error(0, "ERROR: not initilaized mlx\n");
}

void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32,
			"so_loong");
	if (game->win == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		end_error(0, "ERROR: Window creation failed\n");
	}
}
