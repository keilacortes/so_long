// header

#include "so_long.h"

int is_rectangular(t_game *game, int width, int height)
{
    int i;
    i = 0;
    while (i < height)
    {
        if ((int)ft_strlen(game->map[i]) != width)
            return (0);
        i++;
    }
    return (1);
}

int valid_walls(t_game *game, int width, int height)
{
    int i;

    i = 0;
    while (i < width)
    {
        if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int valid_components(t_game *game)
{
    int i;
    int j;
    int player_count;
    int exit_count;
    int collect_count;

    player_count = 0;
    exit_count = 0;
    collect_count = 0;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
                player_count++;
            else if (game->map[i][j] == 'E')
                exit_count++;
            else if (game->map[i][j] == 'C')
                collect_count++;
            j++;
        }
        i++;
    }
    if (player_count != 1 || exit_count != 1 || collect_count < 1)
        return (0);
    game->collect = collect_count;
    return (1);
}

int valid_map(t_game *game)
{
    int width;
    int height;

    width = game->map_width;
    height = game->map_height;
    if (!is_rectangular(game, width, height))
    {
        ft_printf("Error!\nThe map is not rectangular\n");
        return (0);
    }
    if (!valid_walls(game, width, height))
    {
        ft_printf("Error!\nThe map is not enclosed by walls\n");
        return (0);
    }
    if (!valid_components(game))
    {
        ft_printf("Error\nThe map has invalid elements\n");
        return (0);
    }
    return (1);
}
