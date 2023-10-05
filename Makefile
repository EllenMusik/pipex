NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
#DEBUG = -fsanitize=address -g
HEADER = pipex.h
RM = rm -rf

SRC_DIR	=	./src
OBJ_DIR	=	./obj

LIBFT	=	libft/libft.a

PRINTF	=	ft_printf/libftprintf.a

FILES	=	pipex pipex_help_function\


SRC		=	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJ		=	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))


all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(MAKE) bonus -C libft
	$(CC) $(DEBUG) $(OBJ) $(LIBFT) -o $(NAME)

#$(O_FILES):
#	cc $(CFLAGS) -I /usr/X11/include -c $(FILES) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re