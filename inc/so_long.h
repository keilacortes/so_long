//header

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "mlx.h"

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_position
{
	int	x;
	int	y;
} t_position;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
} t_textures;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	int			collect;
	int			collected;
	int			moves;
	int			exit_pos;
	t_position	player_pos;
	void		*mlx;
	void		*win;
	t_textures	textures;
} t_game;

void	error_exit(char *message);
char	**read_map(const char *file, t_game *game);
void	free_map(char **map);
void	trim_line(char *line);
void	find_position(char **map, int *x, int *y, char c, int width, int height);
int		valid_map(t_game *game);
int		valid_path(t_game *game);
void	init_game(t_game *game);
void	*load_texture(void *mlx, char *file_path);
void	put_texture_to_window(t_game *game, void *texture, int x, int y);
void	render_move(t_game *game, int old_x, int old_y, int new_x, int new_y);
int		handle_expose(t_game *game);
void	render_map(t_game *game);
void	load_all_textures(t_game *game);
void	cleanup_textures(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		window_close(t_game *game);

#endif
