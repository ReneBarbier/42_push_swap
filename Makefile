NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj/
SRCS_DIR = srcs/
BONUS_DIR = bonus/

LIBFT_PATH = ./libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

FT_PRINTF_PATH = ./ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

SOURCES =	main.c \
			ft_atol.c \
			ft_lists.c \
			utils.c \
			moves1.c \
			moves2.c \
			input_check.c \
			sort_low.c \
			algorithm1.c \
			algorithm2.c \
			algorithm3.c

BONUS_SRC =	checker_bonus.c \
			ft_lists_bonus.c \
			input_check_bonus.c \
			moves_bonus.c \
			ft_atol_bonus.c \
			get_next_line.c \
			get_next_line_utils.c

OBJECTS = $(addprefix $(OBJS_DIR), $(SOURCES:.c=.o))

BONUS_OBJECTS = $(addprefix $(OBJS_DIR), $(BONUS_SRC:.c=.o))

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/push_swap.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Compiling $< ...

$(OBJS_DIR)%.o : $(BONUS_DIR)%.c inc/checker.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Compiling $< ...

all: subsystems $(OBJS_DIR) $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo push_swap compiled 

$(OBJS_DIR):
	-@mkdir -p $(OBJS_DIR)

bonus: subsystems $(OBJS_DIR) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS)
	@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(BONUS_NAME)
	@echo Checker compiled

subsystems:
	@make bonus -C $(LIBFT_PATH) all --no-print-directory
	@make -C $(FT_PRINTF_PATH) all --no-print-directory

clean :
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@make -C $(FT_PRINTF_PATH) clean --no-print-directory
	@rm -fr $(OBJS_DIR)
	@echo Deleting all objects

fclean : clean
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@make -C $(FT_PRINTF_PATH) fclean --no-print-directory
	@rm -f $(NAME) $(BONUS_NAME)
	@echo Deleting all

re: fclean all

.PHONY: all clean fclean re