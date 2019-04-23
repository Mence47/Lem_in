# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrestles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 21:05:52 by vrestles          #+#    #+#              #
#    Updated: 2019/03/16 20:15:51 by rtroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = both

NAME_LEM = lem-in
NAME_VISU = visu-hex

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

LIB_DIR = ./src/libft
LIBFT = $(LIB_DIR)/libft.a

SRC_LEM = algorithm/main.c \
	algorithm/print_result.c \
	algorithm/queue.c \
	algorithm/solver.c \
	algorithm/graph_init_help.c \
	algorithm/init_graph.c \
	algorithm/list_func.c \
	algorithm/path_func.c \
	algorithm/finder.c \
	algorithm/new_alg.c \
	algorithm/calc_dist.c

SRC_VISU = visual/ants.c \
	visual/area_rectangle.c \
	visual/big_map_solver.c \
	visual/change_coordinates.c \
	visual/coord_array.c \
	visual/drawing.c \
	visual/get_graph_visual.c \
	visual/get_set.c \
	visual/get_ticks.c \
	visual/main_visu.c \
	visual/make_edges.c \
	visual/rendering.c \
	visual/visual_init.c \
	visual/error_messages.c \
	visual/delete_for_visual_part2.c \
	visual/delete_for_visual.c

SRC_COMMON = common/graph_functions.c \
	common/graph_help_func.c \
	common/clean_func.c

OBJ_LEM = $(addprefix $(OBJ_DIR)/, $(SRC_LEM:.c=.o))
OBJ_VISU = $(addprefix $(OBJ_DIR)/, $(SRC_VISU:.c=.o))
OBJ_COMMON = $(addprefix $(OBJ_DIR)/, $(SRC_COMMON:.c=.o))

CC = gcc 
CFLAGS_LEM = -Wall -Wextra -Werror  -I$(INC_DIR)
CFLAGS_VISU = -g -c -Wall -Wextra -Werror -I$(INC_DIR) `sdl2-config --cflags`
LFLAGS_VISU = `sdl2-config --libs` -lSDL2_ttf -lm

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/common
	@mkdir -p $(OBJ_DIR)/algorithm
	@mkdir -p $(OBJ_DIR)/visual

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_COMMON) $(OBJ_LEM) $(OBJ_VISU)
	@$(CC) $(OBJ_LEM) $(OBJ_COMMON) -o $(NAME_LEM) $(LIBFT)
	@$(CC) $(LFLAGS_VISU) $(OBJ_VISU) $(OBJ_COMMON) -o $(NAME_VISU) $(LIBFT)
	@printf "Binary files $(NAME_LEM) and $(NAME_VISU) are ready to use \033[0;32m✔\033[0m\n"

$(NAME_LEM): $(LIBFT) $(OBJ_DIR) $(OBJ_COMMON) $(OBJ_LEM)
	@$(CC) $(OBJ_LEM) $(OBJ_COMMON) -o $(NAME_LEM) $(LIBFT)
	@printf "Binary file $(NAME_LEM) is ready to use \033[0;32m✔\033[0m\n"

$(NAME_VISU): $(LIBFT) $(OBJ_DIR) $(OBJ_COMMON) $(OBJ_VISU)
	@$(CC) $(LFLAGS_VISU) $(OBJ_VISU) $(OBJ_COMMON) -o $(NAME_VISU) $(LIBFT)
	@printf "Binary file $(NAME_VISU) is ready to use \033[0;32m✔\033[0m\n"

$(OBJ_LEM): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS_LEM) -o $@ -c $<

$(OBJ_VISU): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS_VISU) -o $@ -c $<

$(OBJ_COMMON): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS_VISU) -o $@ -c $<

$(LIBFT):
	@make -C $(LIB_DIR)
	@printf "Library $(LIBFT) is recompiled \033[0;32m✔\033[0m\n"

clean:
	@make clean -C $(LIB_DIR)
	@rm -f $(OBJ_LEM) $(OBJ_VISU) $(OBJ_COMMON)
	@rm -rf $(OBJ_DIR)
	@printf "All object files in all folders are deleted \033[0;31m✘\033[0m\n"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME_LEM) $(NAME_VISU)
	@printf "All binary files are deleted \033[0;31m✘\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
