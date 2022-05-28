NAME			= solong.a
CC				= gcc
APP				= so_long
CFLAGS			= -Wall -Werror -Wextra -I.
FILES			= $(shell find . -type f ! -name "bonus_*.c" -name "mandatory_*.c")
OBJ				= $(FILES:%.c=%.o)
BONUS			= bonus/bonus_so_long.c mandatory_move_count_print.c mandatory_check_map.c mandatory_check_map_2.c mandatory_collision.c mandatory_create_image.c mandatory_entity.c mandatory_location_process.c mandatory_move.c mandatory_points.c bonus/bonus_animation.c bonus/bonus_enemy.c bonus/bonus_enemy_move.c bonus/bonus_game_over.c bonus/bonus_hook_events.c bonus/bonus_player_move.c
LIBFT			= srcs/libft/libft.a
GETNEXT			= srcs/get_next_line/getnextline.a

all: make-diff run

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

bonus: $(BOBJS)
	$(CC) -o so_long_bonus $(BONUS) $(LIBFT) $(GETNEXT) -framework OpenGL -framework AppKit -L./mlx -lmlx

make-diff:
	@make -C mlx
	@make -C srcs/libft
	@make -C srcs/get_next_line

run:
	$(CC) -o $(APP) $(FILES) $(LIBFT) $(GETNEXT) -framework OpenGL -framework AppKit -L./mlx -lmlx

clean:
	@rm -f *.o
	@rm -f bonus/*.o

fclean: clean
	@rm -f $(NAME) $(APP) 
	@rm -f so_long_bonus

re : fclean all

.PHONY: all bonus clean fclean re make-diff run

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