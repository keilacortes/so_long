// header

#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }
    t_game game;
    game.map = read_map(argv[1], &game);
    if (!game.map)
    {
        ft_printf("Error: Could not read map file.\n");
        return 1;
    }
    if (!valid_map(&game))
    {
        ft_printf("Error: Invalid map.\n");
        free_map(game.map);
        return 1;
    }
    int i = 0;
    while(game.map[i])
    {
        ft_printf("%s\n", game.map[i]);
        i++;
    }
    return 0;
}