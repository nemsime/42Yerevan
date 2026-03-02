#include "../include/cub3d.h"

int main(int argc, char **argv)
{
    t_game game;
    validation_stage(argc,argv,&game);
    printf("esim\n");
    printf("%s\n",game.assets.no);
    printf("%s\n",game.assets.ea);
    printf("%s\n",game.assets.so);
    printf("%s\n",game.assets.we);
    printf("%d\n",game.assets.floor_color);
    printf("%d\n",game.assets.ceiling_color);
}