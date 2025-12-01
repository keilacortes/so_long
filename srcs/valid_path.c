// header

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, width, height);
	flood_fill(map, x - 1, y, width, height);
	flood_fill(map, x, y + 1, width, height);
	flood_fill(map, x, y - 1, width, height);
}

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		map_copy[i] = malloc(game->map_width + 1);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
		ft_strlcpy(map_copy[i], game->map[i], game->map_width + 1);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	is_reachable(t_game *game, char **map_copy)
{
	int	i;
	int	j;
	int	collectibles_reachable;
	int	exit_reachable;

	collectibles_reachable = 1;
	exit_reachable = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C' && map_copy[i][j] != 'V')
				collectibles_reachable = 0;
			if (game->map[i][j] == 'E' && map_copy[i][j] == 'V')
				exit_reachable = 1;
			j++;
		}
		i++;
	}
	return (collectibles_reachable && exit_reachable);
}

int	valid_path(t_game *game)
{
	char	**map_copy;
	int		result;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_pos.x, game->player_pos.y,
				game->map_width, game->map_height);
	result = is_reachable(game, map_copy);
	free_map(map_copy);
	return (result);
}
