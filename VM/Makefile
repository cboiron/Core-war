#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 18:10:12 by abrichar          #+#    #+#              #
#    Updated: 2018/05/04 02:38:28 by cboiron          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

CFLAG = -Wall -Wextra
CPPFLAGS = -Iincludes

SRC_NAME = main.c create_arena.c param.c read_champ.c load_champs.c play.c \
		   add.c ld.c ldi.c live.c st.c sti.c sub.c zjmp.c \
		   fork.c lld.c aff.c and.c or.c xor.c \
		   instructions_param.c process.c get_instruction.c check_lives.c \
		   is_reg.c write_in_memory.c and_or_xor.c  mod.c get_types.c \
		   free_list.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = src
OBJ_PATH = obj
INC_PATH = includes
LIB_PATH = ../libft/

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH)/, libft.a)

all: $(NAME)

$(LIB):
	@make -C ../libft

$(NAME): $(OBJ) $(LIB)
	@gcc $(CFLAG) $(SRC) $(LIB) -o $(NAME) -I $(INC_PATH) -Ilibft/includes

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf libft/obj

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/corewar.h
