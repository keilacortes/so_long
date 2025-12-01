// header

#include "so_long.h"

void	*load_texture(void *mlx, char *file_path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, file_path, &width, &height);
	return (img);
}

void	put_texture_to_window(t_game *game, void *texture, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, texture, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_move(t_game *game, int old_x, int old_y, int new_x, int new_y)
{
	put_texture_to_window(game, game->textures.floor, old_x, old_y);
	put_texture_to_window(game, game->textures.player, new_x, new_y);
}
