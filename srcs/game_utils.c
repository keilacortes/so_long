// header

#include "so_long.h"

int	handle_expose(t_game *game)
{
	render_map(game);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		window_close(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

int	window_close(t_game *game)
{
	ft_printf("Closing game...\n");
	cleanup_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	ft_printf("Game closed successfully!\n");
	exit(0);
}

void	init_game(t_game *game)
{
	int	win_width;
	int	win_height;

	game->mlx = mlx_init();
	win_width = game->map_width * TILE_SIZE;
	win_height = game->map_height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So Long");
	game->collected = 0;
	game->moves = 0;
	ft_printf("Game initialized successfully!\n");
	load_all_textures(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, window_close, game);
	mlx_hook(game->win, 12, 1L<<15, handle_expose, game);
	ft_printf("Use WASD to move\n");
	ft_printf("Collect all items and reach the exit!\n");
}
