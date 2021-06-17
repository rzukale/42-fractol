# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 17:37:01 by rzukale           #+#    #+#              #
#    Updated: 2020/08/17 18:35:15 by rzukale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# src and obj files
SRC = 	main.c init.c draw.c fractal_algos.c fractal_bonus.c fractal_inits.c fractal_inits2.c hooks.c manipulations.c validate.c fractal_utils.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ft library
FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft/includes
FT_LNK = -L ./libft -l ft

# minilibx
MLX_INC = -I /usr/local/include
MLX_LNK = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# sub-directories
SCRDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SCRDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME) -lpthread

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
.PRECIOUS: author