//header

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "mlx.h"

typedef struct s_game
{
    char    **map;
    int     map_width;
    int     map_height;
    int     collect;
    void    *mlx;
    void    *win;
} t_game;

//map_read
char    **read_map(const char *file, t_game *game);
//utils
void    free_map(char **map);
//valid_map
int     valid_map(t_game *game);

#endif