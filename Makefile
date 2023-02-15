# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 11:54:31 by diserran          #+#    #+#              #
#    Updated: 2023/02/15 16:38:27 by diserran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g3
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

LIBFT := src/libft/
GNL := src/get_next_line/

SRCS        :=      $(GNL)get_next_line.c \
					src/so_long.c \
					src/so_long_utils.c \
					src/map_check.c \
					src/map_check_path.c \
					src/graphics_utils.c

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -I $(LIBFT) -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

define SOLONG
$(RED) ____ $(CYAN)____ $(YELLOW)____ $(GREEN)____ $(BLUE)____ $(RED)____ $(CYAN)____ $(GREEN)____ $(CLR_RMV)
$(RED)||R ||$(CYAN)|E ||$(YELLOW)|_ ||$(GREEN)|L ||$(BLUE)|A ||$(RED)|R ||$(CYAN)|G ||$(GREEN)|O ||$(CLR_RMV)
$(RED)||__||$(CYAN)|__||$(YELLOW)|__||$(GREEN)|__||$(BLUE)|__||$(RED)|__||$(CYAN)|__||$(GREEN)|__||$(CLR_RMV)
$(RED)|/__\|$(CYAN)/__\|$(YELLOW)/__\|$(GREEN)/__\|$(BLUE)/__\|$(RED)/__\|$(CYAN)/__\|$(GREEN)/__\|$(CLR_RMV)

endef
export SOLONG

$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			@ $(MAKE) -C $(LIBFT) bonus
			$(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit -fsanitize=address $(LIBFT)libft.a
			@echo "$(GREEN)$(NAME) created[0m ✔️"
			@echo "$$SOLONG"

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ $(MAKE) -C $(LIBFT) clean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ rm ./mlx/libmlx.a
			@ $(MAKE) -C $(LIBFT) fclean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


