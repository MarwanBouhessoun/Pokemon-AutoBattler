##
## POKEMON_auto PROJECT, 2025
## Makefile
## File description:
## make something
##

SRC_FILES	=	main.c				\
				print_pokemon.c 	\
				check_pokemon.c 	\
				init_pokemons.c 	\
				poke_battle.c 	 	\
				free_pokemons.c 	\

SRC			=	$(addprefix src/, $(SRC_FILES))

OBJ			=	$(SRC:.c=.o)

NAME		=	pokefight

CFLAGS	=	-Wextra -Wall -iquote ./include -g3

all: $(NAME)

$(NAME):	 $(OBJ)
	clang -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) ./$(NAME)

re:	 fclean all
