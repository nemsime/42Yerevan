#include "../include/cub3d.h"

void	free_map(t_map *map)
{
	t_map_node	*tmp;
	t_map_node	*next;

	if (!map)
		return;
	tmp = map->head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->line);
		free(tmp);
		tmp = next;
	}
	map->head = NULL;
	map->width = 0;
	map->height = 0;
}

void	free_game_content(t_game *game)
{
	if (game->assets.ea)
		free(game->assets.ea);
	if (game->assets.we)
		free(game->assets.we);
	if (game->assets.so)
		free(game->assets.so);
	if (game->assets.no)
		free(game->assets.no);
}

int	main(int argc, char **argv)
{
	t_game game;
	validation_stage(argc, argv, &game);
	free_game_content(&game);
	free_map(&game.map);
}