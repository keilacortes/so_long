//header

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "mlx.h"

# define TILE_SIZE 64

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_game
{
    char    **map;
    int     map_width;
    int     map_height;
    int     collect;
    int     collected;
    int     moves;
    int     exit_pos;
    t_position     player_pos;
    void    *mlx;
    void    *win;
} t_game;

//map_read
char    **read_map(const char *file, t_game *game);
//utils
void    free_map(char **map);
void    trim_line(char *line);
void    error_exit(char *message);
void    find_player_position(t_game *game);
//valid_map
int     valid_map(t_game *game);
//valid_path
int     valid_path(t_game *game);

#endif