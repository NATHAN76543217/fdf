.PHONY: all clean fclean re

# Name of file
NAME			=	fdf
LIBFT_NAME		= 	libft.a
MINILIBX_NAME	= 	libmlx.a

# Name directory
PATH_INC		=	includes
PATH_SRC		=	srcs
PATH_OBJ		=	objs
PATH_LIBFT		= 	libft
PATH_MINILIBX	= 	minilibx
PATH_LIBFT_INC	= 	$(PATH_LIBFT)/$(PATH_INC)
PATH_MINILIBX_INC	= 	$(PATH_MINILIBX)

# List of sources
SRCS_FILES		=	main.c fdf.c
INC_FILES		=	fdf.h 
LIBFT_INC_FILES	=	libft.h 
MLX_INC_FILES	=	mlx.h 


SRCS		=	$(addprefix $(PATH_SRC)/, $(SRCS_FILES))
OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRCS:.c=.o))
INCS		=	$(addprefix $(PATH_INC)/, $(INC_FILES)) \
				$(addprefix $(PATH_LIBFT_INC)/, $(LIBFT_INC_FILES)) \
				$(addprefix $(PATH_MINILIBX_INC)/, $(MLX_INC_FILES))

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra 
COMP_LIB	=	-L$(PATH_LIBFT) -lft
COMP_ADD	=	-I$(PATH_INC) -I$(PATH_LIBFT_INC) -I$(PATH_MINILIBX_INC) $(COMP_LIB)
COMP_DEB	=	-g3 -fsanitize=address


# Others Command
RM			=	/bin/rm
# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init: $(LIBFT_NAME) $(MINILIBX_NAME)
	echo $(INCS)
	@ mkdir -p $(PATH_OBJ)/$(PATH_SRC)

$(NAME): $(OBJS) $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -o $(NAME) $(OBJS)

$(PATH_OBJ)/%.o : %.c  $(INCS)
	@ ($(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c  $(INCS)
	@ ($(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

$(MINILIBX_NAME):
	@ printf "\033[0m"
	@ make -C $(PATH_MINILIBX)
	@ printf "\033[0;38;5;82mCompilation de la \033[1m$@ \033[0;38;5;82mreussis.\n\033[0m"

$(LIBFT_NAME):
	@ printf "\033[0m"
	@ make -C $(PATH_LIBFT)
	@ printf "\033[0;38;5;82mCompilation de la \033[1m$@ \033[0;38;5;82mreussis.\n\033[0m"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ make clean -C $(PATH_LIBFT)
	@ make clean -C $(PATH_MINILIBX)
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ make fclean -C $(PATH_LIBFT)
	@ $(RM) -rf $(NAME)

re: fclean all