NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRCS = $(addprefix srcs/, main.c \
                          map_read.c \
						  so_long_utils.c \
						  valid_map.c \
                  )

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./inc -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re