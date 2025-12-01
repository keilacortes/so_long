// header

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map_file.ber>");
	game.map = read_map(argv[1], &game);
	if (!game.map)
		error_exit("Could not read map file\n");
	if (!valid_map(&game))
		free_map(game.map);
	init_game(&game);
	mlx_loop(game.mlx);
}
