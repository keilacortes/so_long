// header

#include "so_long.h"

int	is_rectangular(t_game *game, int width, int height)
{
	int	i;
	i = 0;
	while (i < height)
	{
		if ((int)ft_strlen(game->map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	valid_walls(t_game *game, int width, int height)
{
	int	i;

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

void	count_components(t_game *game, int *player, int *exit, int *collect)
{
	int	i;
	int	j;

	*player = 0;
	*exit = 0;
	*collect = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				(*player)++;
			else if (game->map[i][j] == 'E')
				(*exit)++;
			else if (game->map[i][j] == 'C')
				(*collect)++;
			j++;
		}
		i++;
	}
}

int	valid_components(t_game *game)
{
	int	player;
	int	exit;
	int	collect;

	count_components(game, &player, &exit, &collect);
	game->collect = collect;
	if (player == 1)
		find_position(game->map, &game->player_pos.x, &game->player_pos.y, 'P', game->map_width, game->map_height);
	if (player != 1 || exit != 1 || collect < 1)
		return (0);
	return (1);
}

int	valid_map(t_game *game)
{
	if (!is_rectangular(game, game->map_width, game->map_height))
	{
		error_exit("The map is not rectangular\n");
		return (0);
	}
	if (!valid_walls(game, game->map_width, game->map_height))
	{
		error_exit("The map is not enclosed by walls\n");
		return (0);
	}
	if (!valid_components(game))
	{
		error_exit("The map has invalid elements\n");
		return (0);
	}
	if (!valid_path(game))
	{
		error_exit("No valid path in the map\n");
		return (0);
	}
	return (1);
}
