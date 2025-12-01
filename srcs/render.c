// header

#include "so_long.h"

void	load_all_textures(t_game *game)
{
	game->textures.wall = load_texture(game->mlx, "./assets/wall.xpm");
	game->textures.floor = load_texture(game->mlx, "./assets/floor.xpm");
	game->textures.player = load_texture(game->mlx, "./assets/player.xpm");
	game->textures.collectible = load_texture(game->mlx, "./assets/collectible.xpm");
	game->textures.exit = load_texture(game->mlx, "./assets/exit.xpm");
	if (!game->textures.wall || !game->textures.floor || !game->textures.player || !game->textures.collectible || !game->textures.exit)
		error_exit("Failed to load one or more textures");
}

void	cleanup_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile_type;

	tile_type = game->map[y][x];
	if (tile_type == '0')
		put_texture_to_window(game, game->textures.floor, x, y);
	if (tile_type == '1')
		put_texture_to_window(game, game->textures.wall, x, y);
	else if (tile_type == 'C')
		put_texture_to_window(game, game->textures.collectible, x, y);
	else if (tile_type == 'E')
		put_texture_to_window(game, game->textures.exit, x, y);
	else if (tile_type == 'P')
		put_texture_to_window(game, game->textures.player, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
