//header

#include "so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width || new_y < 0 || new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player_pos.x;
	old_y = game->player_pos.y;
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_move(game, old_x, old_y, new_x, new_y);
}

void	collect_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		ft_printf("Item collected! (%d/%d)\n", game->collected, game->collect);
		game->map[y][x] = '0';
		put_texture_to_window(game, game->textures.player, x, y);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.x + dx;
	new_y = game->player_pos.y + dy;
	
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->collect)
		{
			update_player_position(game, new_x, new_y);
			ft_printf("Congratulations! You won in %d moves!\n", game->moves);
			window_close(game);
			return ;
		}
		else
		{
			ft_printf("You need to collect all items first! (%d/%d)\n", 
				game->collected, game->collect);
			return ;
		}
	}
	collect_item(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
}
