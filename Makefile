##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -I./include -lm

SRC	=	src/clics_handlings.c		\
		src/clock_event.c			\
		src/draw_statue.c			\
		src/global_event.c			\
		src/init_player.c			\
		src/main_rpg.c				\
		src/main.c					\
		src/mouse_clic_s_0.c		\
		src/my_putstr.c				\
		src/my_strlen.c				\
		src/options.c				\
		src/player_rects.c			\
		src/save.c					\
		src/save_to_file.c			\
		src/my_strcat.c				\
		src/my_strcpy.c				\
		src/itos.c					\
		src/menu/click_menu2.c		\
		src/menu/check_mouse.c		\
		src/menu/check_mouse2.c		\
		src/menu/click_menu.c		\
		src/menu/draw_menu.c		\
		src/menu/menu_destroy.c		\
		src/menu/menu_set_sprites.c	\
		src/menu/menu_set2.c		\
		src/menu/particules.c		\
		src/get_next_char.c			\
		src/load_map.c				\
		src/create_perspective.c	\
		src/tuto/draw_tuto.c		\
		src/tuto/tuto.c				\
		src/keys_handlings.c		\
		src/handling_items.c		\
		src/death/script_death.c			\
		src/init.c					\
		src/fight/draw_fights.c		\
		src/fight/fights.c			\
		src/fight/update_fights.c	\
		src/fight/player_deplacements.c	\
		src/fight/spells.c				\
		src/fight/launch_spell.c\
		src/fight/player_fight_rects.c	\
		src/generate_random.c	\
		src/fight/update_spell.c	\
		src/fights_spawns.c				\
		src/fight/black_hole.c			\
		src/fight/fireball.c			\
		src/fight/heals.c				\
		src/fight/shield.c				\
		src/fight/speed.c				\
		src/my_ftoa.c					\
		src/end_script/draw_end_script.c\
		src/end_script/end_script.c		\


SRC2 =	tests/test_main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

NAME2	=	units

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info

re:	fclean all

tests_run:
	$(CC) -o $(NAME2) $(SRC2) --coverage -lcriterion -I./include
	./$(NAME2)