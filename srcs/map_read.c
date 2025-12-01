// header

#include "so_long.h"

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count++;
	}
	return (count);
}

char	**allocate_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map)
		return (NULL);
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		trim_line(line);
		if (line[0] == '\0')
		{
			free(line);
			break;
		}
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	game->map_height = i;
	return (map);
}

char	**read_map(const char *file, t_game *game)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->map_height = count_lines(fd);
	if (game->map_height == 0)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = allocate_map(fd, game);
	close(fd);
	if (!map || game->map_height == 0 || map[0] == NULL)
		return (NULL);
	game->map = map;
	game->map_width = ft_strlen(map[0]);
	return (map);
}
