// header

#include "so_long.h"

void    free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void trim_line(char *line)
{
    int len;

    len = ft_strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
    {
        line[len - 1] = '\0';
        len--;
    }
}

void    error_exit(char *message)
{
    ft_printf("Error\n%s", message);
    exit(1);
}

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos.x = j;
				game->player_pos.y = i;
				return;
			}
			j++;
		}
		i++;
	}
	game->player_pos.x = -1;
	game->player_pos.y = -1;
}