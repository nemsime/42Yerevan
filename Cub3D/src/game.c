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

int	main(int argc, char **argv)
{
	t_game game;
	validation_stage(argc, argv, &game);
	// free_game_content(&game);
	printf("%d\n", game.state.so);
	printf("%d\n", game.state.no);
	printf("esim\n");
	printf("%s\n", game.assets.no);
	printf("%s\n", game.assets.ea);
	printf("%s\n", game.assets.so);
	printf("%s\n", game.assets.we);
	printf("%d\n", game.assets.floor_color);
	printf("%d\n", game.assets.ceiling_color);
	free_game_content(&game);
}