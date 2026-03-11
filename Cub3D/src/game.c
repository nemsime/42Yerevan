#include "../include/cub3d.h"

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

void free_map(t_map *map)
{
    t_map_node *tmp;
    while (map->head)
    {
        tmp = map->head;
        map->head = map->head->next;
        free(tmp->line);
        free(tmp);
    }
    map->height = 0;
    map->width = 0;
}

int	main(int argc, char **argv)
{
	t_game game;
	validation_stage(argc, argv, &game);
	// free_game_content(&game);
	printf("%d\n", game.assets.state.so);
	printf("%d\n", game.assets.state.no);
	printf("esim\n");
	printf("%s\n", game.assets.no);
	printf("%s\n", game.assets.ea);
	printf("%s\n", game.assets.so);
	printf("%s\n", game.assets.we);
	printf("%d\n", game.assets.floor_color);
	printf("%d\n", game.assets.ceiling_color);
	free_game_content(&game);
}