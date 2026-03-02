/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:54:19 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 13:48:40 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	map_validation(argc, argv, &game);
	map_load(argv, &game);
	init_game(&game);
	create_window(&game);
	create_image(&game);
	mlx_hook(game.win, 17, 0L, clear_and_exit, &game);
	mlx_hook(game.win, 2, 1L << 0, move_esc, &game);
	mlx_loop(game.mlx);
	return (0);
}
